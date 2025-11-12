#include <bits/stdc++.h>
using namespace std;
int t,n,b[100005][3],sum;
struct ha{
	int x,y,z,mx,mn,mid,k,fl,id;
	inline bool operator < (const ha &o) const{
		return k>o.k;
	}
};
ha a[100005];
priority_queue<ha> q[3];
inline bool cmp(ha &x,ha &y){
	return b[x.id][x.mx]>b[y.id][y.mx];
}
void ck(int x,ha y){
	q[x].push(y);
	if((int)q[x].size()>(n>>1)){
		ha k=q[x].top();
		q[x].pop();
		if(k.fl==1){
			k.fl=2;
			k.k=(int)2e9;
			ck(k.mn,k);
		}
		else if(!k.fl){
			k.fl=1;
			k.k=b[k.id][k.mid]-b[k.id][k.mn];
			ck(k.mid,k);
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		sum=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
			a[i].mx=max({a[i].x,a[i].y,a[i].z});
			a[i].mn=min({a[i].x,a[i].y,a[i].z});
			b[i][0]=a[i].x,b[i][1]=a[i].y,b[i][2]=a[i].z;
			if(a[i].mx==a[i].x){
				a[i].mx=0;
				if(a[i].mn==a[i].y) a[i].mid=2,a[i].mn=1;
				else a[i].mid=1,a[i].mn=2;
			}
			else if(a[i].mx==a[i].y){
				a[i].mx=1;
				if(a[i].mn==a[i].x) a[i].mid=2,a[i].mn=0;
				else a[i].mid=0,a[i].mn=2;
			}
			else{
				a[i].mx=2;
				if(a[i].mn==a[i].x) a[i].mid=1,a[i].mn=0;
				else a[i].mid=0,a[i].mn=1;
			}
			a[i].k=b[i][a[i].mx]-b[i][a[i].mid];
			a[i].id=i;
		} 
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++) ck(a[i].mx,a[i]);
		while(!q[0].empty()){
			sum+=b[q[0].top().id][0];
			q[0].pop();
		}
		while(!q[1].empty()){
			sum+=b[q[1].top().id][1];
			q[1].pop();
		}
		while(!q[2].empty()){
			sum+=b[q[2].top().id][2];
			q[2].pop();
		}
		printf("%d\n",sum);
	}
	return 0;
}

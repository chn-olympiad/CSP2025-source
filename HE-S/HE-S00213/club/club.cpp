#include<bits/stdc++.h>
using namespace std;
int T,n,a[100010][3],c[100010],b[100010],cnt,ct;
long long sum,sm;
bool cmp(int d,int e){
	return d>e;
}
struct node{
	int id,ids,x;
};
bool operator <(node d,node e){
	return d.x<e.x;
}
priority_queue<node,vector<node>,less<node> > q;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		while(!q.empty()) q.pop();
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		sum=sm=cnt=ct=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
			b[i]=a[i][1]-a[i][0];
			sum+=1ll*a[i][0];
			sm+=1ll*a[i][1];
			q.push(node{0,i,a[i][0]-a[i][1]});
			q.push(node{2,i,a[i][2]-a[i][1]});
		}
		sort(b+1,b+1+n,cmp);
		for(int i=1;i<=n/2;i++){
			sum+=1ll*b[i];
		}
		while(!q.empty()&&(cnt<n/2||ct<n/2)){
			node u=q.top(); q.pop();
			if(u.id==0&&cnt<n/2&&c[u.ids]==0&&(u.x>0||cnt+ct<n/2)){
				sm+=1ll*u.x;
				cnt++;
				c[u.ids]=1;
			}else if(u.id==2&&ct<n/2&&c[u.ids]==0&&(u.x>0||cnt+ct<n/2)){
				sm+=1ll*u.x;
				ct++;
				c[u.ids]=1;
			}
		}
		printf("%d\n",max(sm,sum));
	}
	return 0;
}

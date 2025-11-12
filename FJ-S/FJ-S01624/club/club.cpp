#include<bits/stdc++.h>
using namespace std;
int T,n,a[100005][4],b[4],ans,llen,rlen;
struct df{
	int zhi,xb;
}c[100005][4];
bool cmp(df x,df y){
	return x.zhi>y.zhi;
}
priority_queue<pair<int,int> >l[4];
pair<int,int>p[100005],cida[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		ans=0;
		while(!l[1].empty()){
			l[1].pop();
		}
		while(!l[2].empty()){
			l[2].pop();
		}
		while(!l[3].empty()){
			l[3].pop();
		}
		for(int i = 1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			c[i][1].zhi=a[i][1],c[i][2].zhi=a[i][2],c[i][3].zhi=a[i][3];
			c[i][1].xb=1,c[i][2].xb=2,c[i][3].xb=3;
			sort(c[i]+1,c[i]+4,cmp);
			cida[i]=make_pair(c[i][2].zhi,c[i][2].xb);
			b[c[i][1].xb]++;
			ans+=c[i][1].zhi;
			int cha=c[i][1].zhi-cida[i].first;
			l[c[i][1].xb].push(make_pair(cha,i));
		}
		int t=1,pp=0;
		if(l[t].size()>n/2){
			llen=l[t].size();
			for(int i = 1;i<=llen;i++){
				p[i]=l[t].top();
				l[t].pop();
			}
			rlen=llen;
			while(rlen>n/2){
				ans-=p[rlen].first;
				rlen--;
			}
			cout<<ans<<endl;
			pp=1;
		}
		t=2;
		if(l[t].size()>n/2){
			llen=l[t].size();
			for(int i = 1;i<=llen;i++){
				p[i]=l[t].top();
				l[t].pop();
			}
			rlen=llen;
			while(rlen>n/2){
				ans-=p[rlen].first;
				rlen--;
			}
			cout<<ans<<endl;
			pp=1;
		}
		t=3;
		if(l[t].size()>n/2){
			llen=l[t].size();
			for(int i = 1;i<=llen;i++){
				p[i]=l[t].top();
				l[t].pop();
			}
			rlen=llen;
			while(rlen>n/2){
				ans-=p[rlen].first;
				rlen--;
			}
			cout<<ans<<endl;
			pp=1;
		}
		if(!pp){
			cout<<ans<<endl;
		}
	}
	/*
	1
	4
	4 2 1
	3 2 4
	5 3 4
	3 5 1
	*/
	return 0;
}

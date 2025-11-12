#include <bits/stdc++.h>
using namespace std;
int t,n,ans;
struct person{
	int a,b,c;
}p[100003];
bool cmp(person x,person y){
	if(x.a==y.a){
		if(x.b==y.b)return x.c>y.c;
		return x.b>y.b;
	}
	return x.c>y.c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>p[i].a>>p[i].b>>p[i].c;
		}
		sort(p+1,p+n+1,cmp);
		int cnt[3];
		memset(cnt,0,sizeof cnt);
		for(int i=1;i<=n;i++){
			int x=p[i].a,y=p[i].b,z=p[i].c;
			int maxn=max(x,max(y,z)),minn=min(x,min(y,z));
			int mid=x+y+z-maxn-minn;
			int u,v,w;
			if(maxn==p[i].a)u=1;
			else if(maxn==p[i].b)u=2;
			else u=3;
			if(minn==p[i].a)w=1;
			else if(minn==p[i].b)w=2;
			else w=3;
			v=6-u-w;
			if(cnt[u]==n/2){
				if(cnt[v]==n/2){
					ans+=minn;
					cnt[w]++;
				}else{
					ans+=mid;
					cnt[v]++;
				}
			}else{
				ans+=maxn;
				cnt[u]++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

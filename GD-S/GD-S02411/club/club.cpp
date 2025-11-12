#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
int n,ct[5];
struct Data{
	int x,y,z;
}a[N];
struct Node{
	int x,opt,num;
}b[N<<1];
bool cmp(Node px,Node py){
	return px.x<py.x;
}
ll ans;
bool vis[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int Tst;
	cin>>Tst;
	while(Tst--)
	{
		cin>>n;
		ans=0;
		ct[1]=ct[2]=ct[3]=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].x>>a[i].y>>a[i].z;
			int mx=max(a[i].x,max(a[i].y,a[i].z));
			if(mx==a[i].x) ct[1]++;
			else if(mx==a[i].y) ct[2]++;
			else ct[3]++;
			ans+=mx;
		}
		int now=max(ct[1],max(ct[2],ct[3]));
		if(now<=(n/2)){
			cout<<ans<<"\n";
			continue;
		}
		if(ct[1]==now)
		{
			int m=0;
			for(int i=1;i<=n;i++)
			{
				vis[i]=false;
				int mx=max(a[i].x,max(a[i].y,a[i].z));
				if(mx==a[i].x){
					b[++m]=Node{a[i].x-a[i].y,2,i};
					b[++m]=Node{a[i].x-a[i].z,3,i};
				}
			}
			sort(b+1,b+m+1,cmp);
			int lst=ct[1];
			for(int i=1;i<=m&&lst>(n/2);i++){
				if(vis[b[i].num]) continue;
				ans-=b[i].x;
				vis[b[i].num]=true;
				lst--;
			}
		}
		else if(ct[2]==now)
		{
			int m=0;
			for(int i=1;i<=n;i++)
			{
				vis[i]=false;
				int mx=max(a[i].x,max(a[i].y,a[i].z));
				if(mx==a[i].x) continue;
				if(mx==a[i].y){
					b[++m]=Node{a[i].y-a[i].x,1,i};
					b[++m]=Node{a[i].y-a[i].z,3,i};
				}
			}
			sort(b+1,b+m+1,cmp);
			int lst=ct[2];
			for(int i=1;i<=m&&lst>(n/2);i++){
				if(vis[b[i].num]) continue;
				ans-=b[i].x;
				vis[b[i].num]=true;
				lst--;
			}
		}
		else{
			int m=0;
			for(int i=1;i<=n;i++)
			{
				vis[i]=false;
				int mx=max(a[i].x,max(a[i].y,a[i].z));
				if(mx==a[i].x) continue;
				if(mx==a[i].y) continue;
				b[++m]=Node{a[i].z-a[i].x,1,i};
				b[++m]=Node{a[i].z-a[i].y,2,i};
			}
			sort(b+1,b+m+1,cmp);
			int lst=ct[3];
			for(int i=1;i<=m&&lst>(n/2);i++){
				if(vis[b[i].num]) continue;
				ans-=b[i].x;
				vis[b[i].num]=true;
				lst--;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 

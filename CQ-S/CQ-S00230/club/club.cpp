/*

14:38
นýมห 

*/
#include<bits/stdc++.h>
using namespace std;
namespace Sasuke{
	#define int long long
//	#define ll long long
	#define maxm 500005
	#define maxn 1005
	#define mod 1000000007
	#define inf 0x3f3f3f3f3f3f
	#define msk cerr
	int cas,T,n,m,ans;
	int a[maxm][5];
	int s[maxm];
	multiset<int>t[5];
	signed main(){
		ios::sync_with_stdio(0);
		cin.tie(0);cout.tie(0);
		cin>>T;
		while(T--){
			cin>>n;m=n>>1;s[1]=s[2]=s[3]=0;t[1].clear();t[2].clear();t[3].clear();ans=0;
			for(int i=1;i<=n;i++)cin>>a[i][1]>>a[i][2]>>a[i][3]; 
			for(int i=1;i<=n;i++){
				int mx=max({a[i][1],a[i][2],a[i][3]});ans+=mx;
				if(mx==a[i][1])s[1]++,t[1].insert(a[i][1]-max(a[i][2],a[i][3]));
				else if(mx==a[i][2])s[2]++,t[2].insert(a[i][2]-max(a[i][1],a[i][3]));
				else s[3]++,t[3].insert(a[i][3]-max(a[i][1],a[i][2]));
			}
			int id=0;
			if(s[1]>m)id=1;
			if(s[2]>m)id=2;
			if(s[3]>m)id=3;
			while(s[id]>m){
				int x=*t[id].begin();
				ans-=x;s[id]--;t[id].erase(t[id].find(x));
			}
			cout<<ans<<"\n"; 
		}
		return 0;
	}
} 
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	Sasuke::main();
	return 0; 
} 

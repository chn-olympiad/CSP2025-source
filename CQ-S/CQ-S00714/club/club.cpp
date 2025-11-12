#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,m,a[200001][3],tn[3],vis[200001];
vector<int> v;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;v.clear();memset(vis,0,sizeof vis);
		tn[0]=tn[1]=tn[2]=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i][0]==max({a[i][0],a[i][1],a[i][2]})) ans+=a[i][0],tn[0]++,vis[i]=0;
			else if(a[i][1]==max({a[i][0],a[i][1],a[i][2]})) ans+=a[i][1],tn[1]++,vis[i]=1;
			else if(a[i][2]==max({a[i][0],a[i][1],a[i][2]})) ans+=a[i][2],tn[2]++,vis[i]=2;
		}
		if(tn[0]<=n/2&&tn[1]<=n/2&&tn[2]<=n/2){cout<<ans<<'\n';continue;}
		int f=0;
		if(tn[1]>n/2) f=1;
		if(tn[2]>n/2) f=2;
		for(int i=1;i<=n;i++){
			if(vis[i]==f){
				if(f==0) v.push_back({a[i][f]-max(a[i][1],a[i][2])});
				if(f==1) v.push_back({a[i][f]-max(a[i][0],a[i][2])});
				if(f==2) v.push_back({a[i][f]-max(a[i][1],a[i][0])});
			}
		}
		sort(v.begin(),v.end());int it=0;
//		cout<<tn[f]<<' '<<n/2<<' '<<v.size()<<"\n";
		while(tn[f]>n/2) tn[f]--,ans-=v[it],it++; 
		cout<<ans<<"\n";
	}
	return 0;
}
/*
Ã»ÅÐÏàµÈ²Ý¡£ 
*/

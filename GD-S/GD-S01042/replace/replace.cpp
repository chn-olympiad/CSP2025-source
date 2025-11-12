#include<bits/stdc++.h>
using namespace std;
#define int long long
const int base=13331,mod=998244353,N=1e5+7;
int n,q,pre1[N],pre2[N],p[N],bac1[N],bac2[N];
map<pair<int,int>,int>mp;
signed main(){
	ios::sync_with_stdio(false); 
	cin.tie(0),cout.tie(0);
		freopen("replace.in","r",stdin);
		freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		int h1=0,h2=0;
		for(int i=0;i<s1.size();i++){
			h1=(h1*base+s1[i])%mod;
			h2=(h2*base+s2[i])%mod;
		}
		//cout<<h1<<" "<<h2<<"\n";
		mp[{h1,h2}]++;
	}
	p[0]=1;
	for(int i=1;i<=1e5;i++)p[i]=p[i-1]*base,p[i]%=mod;
	while(q--){
		string a,b;
		int ans=0;
		cin>>a>>b;
		bac1[a.size()+1]=bac2[a.size()+1]=0;
		for(int i=a.size();i>=1;i--){
			bac1[i]=bac1[i+1]*base+a[i-1];
			bac2[i]=bac2[i+1]*base+b[i-1];
			bac1[i]%=mod;
			bac2[i]%=mod;
		}
		for(int i=1;i<=a.size();i++){
			pre1[i]=pre1[i-1]*base+a[i-1];
			pre1[i]%=mod;
			pre2[i]=pre2[i-1]*base+b[i-1];
			pre2[i]%=mod;
		}
		for(int i=1;i<=a.size();i++){
			for(int j=i;j<=a.size();j++){
				int h1,h2;
				if(pre1[i-1]!=pre2[i-1]||bac1[j+1]!=bac2[j+1])continue;
				h1=(pre1[j]-pre1[i-1]*p[j-i+1]%mod+mod)%mod;
				h2=(pre2[j]-pre2[i-1]*p[j-i+1]%mod+mod)%mod;
			//	cout<<i<<" "<<j<<" "<<h1<<" "<<h2<<"\n";
				ans+=mp[{h1,h2}];
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

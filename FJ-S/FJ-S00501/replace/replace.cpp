#include<bits/stdc++.h>
using namespace std;
const unsigned long long mod=1e9+7;
const unsigned long long h=1331;
int n,q,l,r,ans,ss;
string s[200001][2],t1,t2;
unsigned long long u1[200001],u2[200002],h1,h2,t[2000001];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		for(int j=0;j<s[i][0].size();j++){
			u1[i]=(u1[i]*h+s[i][0][j])%mod;
			u2[i]=(u2[i]*h+s[i][1][j])%mod;
		}
		t[s[i][0].size()]++;
	}
	while(q--){
		cin>>t1>>t2;
		l=0,ans=0;
		if(t1.size()!=t2.size()){
			cout<<0<<"\n";
			continue;
		}
		for(int i=0;i<t1.size();i++){
			if(t1[i]!=t2[i]){
				if(l==0) l=i+1;
				r=i+1;
			}
		}
		for(int i=1;i<=l;i++){
			for(int j=r;j<=t1.size();j++){
				ss=r-l+1;
				if(t[ss]==0) continue;
				h1=h2=0;
				for(int k=i;k<=j;k++){
					h1=(h1*h+t1[k-1])%mod;
					h2=(h2*h+t2[k-1])%mod;
				}
				for(int k=1;k<=n;k++){
					if(h1==u1[k]&&h2==u2[k]) ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}


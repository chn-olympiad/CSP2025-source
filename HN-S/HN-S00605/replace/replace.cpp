#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
string s1[200005],s2[200005];
int hash[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		int len=s1[i].size();
		for(int j=0;j<len;j++){
			hash[i]=(long long)(hash[i]*27+s1[i][j]-'a'+1)%mod;
		}
	}
	while(q--){
		cin>>s1[0]>>s2[0];
		int len=s2[0].size();
		for(int i=0;i<len;i++){
			hash[0]=(long long)(hash[0]*27+s2[0][i]-'a'+1)%mod;
		}
		int l=1;
		len=s1[0].size();
		while(l<=len){
			int ans=0;
			for(int i=0;i+l<=len;i++){
				int _hash=0;
				for(int j=0;j<l;j++){
					_hash=(long long)(_hash*27+s1[0][j]-'a'+1)%mod;
				}
				for(int j=1;j<=n;j++){
					if(_hash==hash[j]){
						int hash1;
						for(int k=0;k<len;k++){
							if(k>=i&&k<=i+l) hash1=(long long)(hash1*27+s2[j][k-i]-'a'+1)%mod;
							hash1=(long long)(hash1*27+s1[0][k]-'a'+1)%mod;
						}
						if(hash1==hash[0]) ans++;
					}
				}
			}
			cout<<ans<<endl;
			l++;
		}
	}
	return 0;
} 

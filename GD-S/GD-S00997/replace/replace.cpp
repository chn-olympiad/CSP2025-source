#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+10;
const int maxm=5e6+10;
const int mod1=1e9+7;
const int mod2=1e9+9;
const int bas1=233;
const int bas2=97;
int n,q,L2,lens[maxn],lent[maxn];
string s[maxn][2],t[maxn][2];
namespace task1{
	int v1[maxn][2],v2[maxn][2],pw1[maxm],pw2[maxm],hsh1[maxm],hsh2[maxm];
	get1(int l,int r){
		return (hsh1[r]-hsh1[l-1]*pw1[r-l+1]%mod1+mod1)%mod1;
	}
	get2(int l,int r){
		return (hsh2[r]-hsh2[l-1]*pw2[r-l+1]%mod2+mod2)%mod2;
	}
	void solve(){
		pw1[0]=pw2[0]=1;
		for(int i=1;i<=L2;i++) pw1[i]=pw1[i-1]*bas1%mod1,pw2[i]=pw2[i-1]*bas2%mod2;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=lens[i]-1;j++){
				for(int k=0;k<=1;k++){
					v1[i][k]=(v1[i][k]*bas1%mod1+s[i][k][j]-'a'+1)%mod1;
					v2[i][k]=(v2[i][k]*bas2%mod2+s[i][k][j]-'a'+1)%mod2;
				}
			}
			// cout<<v1[i][0]<<" "<<v1[i][1]<<" "<<v2[i][0]<<" "<<v2[i][1]<<"\n";
		}
		for(int i=1;i<=q;i++){
			hsh1[0]=hsh2[0]=t[i][0][0]-'a'+1;
			int ans=0;
			int hsh1t=t[i][1][0]-'a'+1,hsh2t=t[i][1][0]-'a'+1;
			for(int j=1;j<=lent[i]-1;j++){
				hsh1[j]=(hsh1[j-1]*bas1%mod1+t[i][0][j]-'a'+1)%mod1;
				hsh2[j]=(hsh2[j-1]*bas2%mod2+t[i][0][j]-'a'+1)%mod2;
				hsh1t=(hsh1t*bas1%mod1+t[i][1][j]-'a'+1)%mod1;
				hsh2t=(hsh2t*bas2%mod2+t[i][1][j]-'a'+1)%mod2;
			}
			// cout<<"hsh1 hsh2\n";
			for(int j=0;j<=lent[i]-1;j++){
				// cout<<hsh1[j]<<" "<<hsh2[j]<<"\n";
				for(int p=1;p<=n;p++){
					if(j-lens[p]+1<0) continue;
					if(get1(j-lens[p]+1,j)==v1[p][0]&&get2(j-lens[p]+1,j)==v2[p][0]){
						// cout<<"ok "<<j<<" "<<p<<"\n";
						int tmp1=0,tmp2=0;
						if(j-lens[p]>=0){
							tmp1=hsh1[j-lens[p]]*pw1[lent[i]-1-(j-lens[p])]%mod1;
							tmp2=hsh2[j-lens[p]]*pw2[lent[i]-1-(j-lens[p])]%mod2;
						}
						if((tmp1+v1[p][1]*pw1[lent[i]-1-j]%mod1+hsh1[lent[i]-1]-hsh1[j]*pw1[lent[i]-1-j]%mod1)%mod1==hsh1t&&(tmp2+v2[p][1]*pw2[lent[i]-1-j]%mod2+hsh2[lent[i]-1]-hsh2[j]*pw2[lent[i]-1-j]%mod2)%mod2==hsh2t) ans++;
					}
				}
			}
			// cout<<get1(2,3)<<" "<<get2(2,3)<<"\n";
			cout<<ans<<"\n";
		}
	}
}
namespace task2{
	void solve(){
		
	}
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[i][0]>>s[i][1],lens[i]=s[i][0].size();
	for(int i=1;i<=q;i++){
		cin>>t[i][0]>>t[i][1];
		L2+=t[i][0].size();
		lent[i]=t[i][0].size();
	}
	if(n*L2<=2e6+10) task1::solve();
	// else task2::solve();
}
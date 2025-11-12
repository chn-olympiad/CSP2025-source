#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int maxn=2e5+10;
const int maxm=5e6+10;
const ll base=131;
const int mod=1e9+9;
int n,q,len,sz[maxn];
string s1[maxn],s2[maxn];
vector<ll> h1[maxn],h2[maxn];
ll h[2][maxm],p[maxm];
inline ll subh(int l,int r,ll *h){
	return (h[r]-h[l-1]*p[r-l+1]%mod+mod)%mod;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;cin>>n>>q;
	p[0]=1;
	for(int i=1;i<=5e6;i++) p[i]=p[i-1]*base%mod;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i],len+=s1[i].size();
		h1[i].push_back(0);
		h2[i].push_back(0);
		
		for(char c:s1[i])
			h1[i].push_back((h1[i][h1[i].size()-1]*base+c)%mod);
		for(char c:s2[i])
			h2[i].push_back((h2[i][h2[i].size()-1]*base+c)%mod);
		sz[i]=s1[i].size();
	}
	if(len<=2e3){
		while(q--){
			string t1,t2;cin>>t1>>t2;
			t1=" "+t1;
			t2=" "+t2;
			int m=t1.size()-1,L=0,R=0,ans=0;
			for(int i=1;i<=m;i++){
				if(!L&&t1[i]!=t2[i]) L=i-1;
				h[0][i]=(h[0][i-1]*base+t1[i])%mod;
				h[1][i]=(h[1][i-1]*base+t2[i])%mod;
			}
			for(int i=m;i;i--)
				if(t1[i]!=t2[i]){R=i+1;break;}
			for(int i=1;i<=m;i++){
				for(int j=1;j<=n;j++){
					if(s1[j].size()>i) continue;
					if(h1[j][sz[j]]==subh(i-sz[j]+1,i,h[0])&&h2[j][sz[j]]==subh(i-sz[j]+1,i,h[1])
						&&i-sz[j]<=L&&i+1>=R) ans++;
				}
			}
			cout<<ans<<endl;
		}
	}
	else if(q==1){
		while(q--){
			string t1,t2;cin>>t1>>t2;
			t1=" "+t1;
			t2=" "+t2;
			int m=t1.size()-1,L=0,R=0,ans=0;
			for(int i=1;i<=m;i++){
				if(!L&&t1[i]!=t2[i]) L=i-1;
				h[0][i]=(h[0][i-1]*base+t1[i])%mod;
				h[1][i]=(h[1][i-1]*base+t2[i])%mod;
			}
			for(int i=m;i;i--)
				if(t1[i]!=t2[i]){R=i+1;break;}
			int len=R-L+1;
			ll f1=subh(L,R,h[0]),f2=subh(L,R,h[1]);
			for(int i=1;i<=n;i++){
				for(int j=len;j<=sz[i];j++){
					int l=j-len+1,r=j;
					ll g1=(h1[i][r]-h1[i][l-1]*p[r-l+1]%mod+mod)%mod;
					ll g2=(h2[i][r]-h2[i][l-1]*p[r-l+1]%mod+mod)%mod;
					if(g1==f1&&g2==f2){
						int len1=l-1;
						ll f3=subh(L-len1,L-1,h[0]);
						ll f4=subh(L-len1,L-1,h[1]);
						g1=h1[i][j-1],g2=h2[i][j-1];
						if(g1!=f3||g2!=f4) continue;
						len1=sz[i]-j;
						f3=subh(R+1,R+len1,h[0]);
						f4=subh(R+1,R+len1,h[1]);
						l=j+1,r=sz[i];
						g1=(h1[i][r]-h1[i][l-1]*p[r-l+1]%mod+mod)%mod;
						g2=(h2[i][r]-h2[i][l-1]*p[r-l+1]%mod+mod)%mod;
						if(f3==g1&&f4==g2) ans++;
					}
				}
			}
			cout<<ans<<endl;
		}
	}
	//else sol3::main();
	return 0;
}

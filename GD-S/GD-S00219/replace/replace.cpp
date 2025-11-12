#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353,base=29;
int n,q,sz[200010][2],hs[200010][2],hs1[200010],hs2[200010],hs3[200010],hs4[200010],ycl[200010];
string a[200010][2];
char s1[200010],s2[200010];
map <pair<int,int>,int> mp;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ycl[0]=1;
	for(int i=1;i<=200000;i++){
		ycl[i]=(ycl[i-1]*base)%mod;
	}
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		for(int j=0;j<2;j++){
			cin>>a[i][j];
			sz[i][j]=a[i][j].size();
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<2;j++){
			for(int k=0;k<sz[i][j];k++){
				hs[i][j]=((hs[i][j]*base)%mod+(a[i][j][k]-'a'+1))%mod;
			}
		}
		mp[{hs[i][0],hs[i][1]}]++;
	}
	while(q--){
		cin>>(s1+1)>>(s2+1);
		int sz=strlen(s1+1);
		int h=0,h2=0;
		for(int i=1;i<=sz;i++){
			h=((h*base)%mod+(s1[i]-'a'+1))%mod;
			hs1[i]=h;
			h2=((h2*base)%mod+(s2[i]-'a'+1))%mod;
			hs2[i]=h2;
		}
		h=0,h2=0;
		for(int i=sz;i>=1;i--){
			h=((h*base)%mod+(s1[i]-'a'+1))%mod;
			hs3[i]=h;
			h2=((h2*base)%mod+(s2[i]-'a'+1))%mod;
			hs4[i]=h2;
		}
		int ans=0;
		for(int i=0;i<=sz+1;i++){
			for(int j=i+2;j<=sz+1;j++){
				if(hs1[i]==hs2[i]&&hs3[j]==hs4[j]){
					int l=i+1,r=j-1;
					int len=(r-l+1);
					int hx1=(hs1[r]-(hs1[l-1]*ycl[len])%mod+mod)%mod;
					int hx2=(hs2[r]-(hs2[l-1]*ycl[len])%mod+mod)%mod;
					ans+=mp[{hx1,hx2}];
				}
			}
		}
		cout<<ans<<endl;
	}	
	return 0;
} 
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/

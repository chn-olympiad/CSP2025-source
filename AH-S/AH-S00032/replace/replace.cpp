#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
const int N=200010,base=131;
int n,m,q;
ull h1[N],h2[N];int len[N];
char s1[N],s2[N];
ull h[N],hs,pw[N];
ull get(int l,int r){
	return h[r]-h[l-1]*pw[r-l+1];
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(NULL);
	cin>>n>>q;
	pw[0]=1;
	for(int i=1;i<=N-10;i++) pw[i]=pw[i-1]*base;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;len[i]=strlen(s1);
		for(int j=0;j<len[i];j++){
			h1[i]=h1[i]*base+s1[j]-'a'+1;
			h2[i]=h2[i]*base+s2[j]-'a'+1;
		}
	}
	ull ans=0;
	for(int i=1;i<=q;i++){
		ans=0;
		cin>>(s1+1)>>(s2+1);
		m=strlen(s1+1);
		h[0]=hs=0;
		for(int j=1;j<=m;j++){
			h[j]=h[j-1]*base+s1[j]-'a'+1;
			hs=hs*base+s2[j]-'a'+1;
		}
		for(int j=1;j<=n;j++){
			for(int l=1;l+len[j]-1<=m;l++){
				int r=l+len[j]-1;
				//cout<<l<<' '<<r<<' '<<get(l,r)<<' '<<h1[j]<<' '<<h2[j]<<' '<<h[m]<<' '<<hs<<'\n';
				//cout<<m-r<<'\n';
				if(get(l,r)==h1[j]&&h[m]-h1[j]*pw[m-r]==hs-h2[j]*pw[m-r]) {
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}


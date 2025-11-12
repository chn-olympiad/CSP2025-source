#include<bits/stdc++.h>
using namespace std;
const int N=5e6+5,b=2333,mod=1000100087;
int n,q;
int hsh[N],st[N],slen[N],pw[N];
int h2[N];
int get_h(int *h,int i,int l,int r){
	l+=st[i],r+=st[i];
	return (h[r]-1ll*h[l-1]*pw[r-l+1]%mod+mod)%mod;
}
void init(){
	pw[0]=1;
	for(int i=1;i<N;i++)pw[i]=1ll*pw[i-1]*b%mod;
	int cur=0;
	for(int i=1;i<=n;i++){
		string s,t;cin>>s>>t;
		int len=s.size();s=' '+s,t=' '+t;st[i]=cur,slen[i]=len;
		for(int j=1;j<=len;j++)cur++,hsh[cur]=(1ll*hsh[cur-1]*b+(s[j]-'a')*29+(t[j]-'a'))%mod;
	}
}
namespace sub1{
	void main(){
		init();
		while(q--){
			string s,t;cin>>s>>t;
			if(s.size()!=t.size()){
				cout<<0<<'\n';continue;
			}
			int len=s.size();s=' '+s,t=' '+t;
			for(int i=1;i<=len;i++)h2[i]=(1ll*h2[i-1]*b+(s[i]-'a')*29+(t[i]-'a'))%mod;
			int ll=0,rr=0;
			for(int i=1;i<=len;i++)if(s[i]!=t[i]){
				if(!ll)ll=i;
				rr=i;
			}
			int cnt=0;
			for(int i=1;i<=n;i++)for(int l=1;l<=slen[i]-(rr-ll+1)+1;l++){
				int r=l+(rr-ll+1)-1;
				//cerr<<i<<' '<<l<<' '<<r<<' '<<ll<<' '<<rr<<'\n';
				if(get_h(hsh,i,l,r)==get_h(h2,0,ll,rr)){
					//cerr<<'#'<<i<<' '<<1<<' '<<slen[i]<<' '<<ll-l+1<<' '<<rr+(slen[i]-r)<<' '<<len<<'\n';
					if(ll-l+1>0&&rr+(slen[i]-r)<=len&&get_h(hsh,i,1,slen[i])==get_h(h2,0,ll-l+1,rr+(slen[i]-r)))cnt++;
				}
			}
			cout<<cnt<<'\n';
		}
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);freopen("replace.out","w",stdout);
	cin>>n>>q;
	sub1::main();
} 

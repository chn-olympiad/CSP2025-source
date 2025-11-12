#include<bits/stdc++.h>
using namespace std;
using ull=unsigned long long;
const ull P=131;
const int MX=5e6+5,N=2e5+5;
int n,q;
string s[N],t[N],a,b;
int solve(){
	a='$'+a+'$',b='$'+b+'$';
	int res=0,lna=a.size(), lnb=b.size();
	for(int pra=0,prb=0;pra<lna&&prb<lnb;pra++,prb++){
		if(a[pra]!=b[prb]) break;
		for(int sfa=lna-1,sfb=lnb-1;sfa>pra+1&&sfb>prb+1;sfa--,sfb--){
			if(a[sfa]!=b[sfb]) {
				break;
			}
			string ya=a.substr(pra+1,sfa-pra-1);
			string yb=b.substr(prb+1,sfb-prb-1);
			for(int i=1;i<=n;i++){
				if(s[i]==ya&&t[i]==yb) {
					res++;
				}
			}
		}
	}
	return res;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) {
		cin>>s[i]>>t[i];
	}
	while(q--){
		cin>>a>>b;
		cout<<solve()<<endl;
	}
	//前缀与后缀相同
	//枚举前缀 和后缀 
	return 0;
}

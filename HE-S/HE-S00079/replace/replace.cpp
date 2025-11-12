#include<bits/stdc++.h>
using namespace std;
const long long N=5e6+10;
long long n,q,ll,rr,ans;
struct lefrigh{
	long long l,r;
}lr[N];
string s,t;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(long long i=1;i<=n;i++){
		cin>>s;
		bool yes=0;
		for(long long j=0;j<s.length();j++){
			if(yes==0){
				if(s[j]=='b'){
					yes=1;
					continue;
				}
				else lr[i].l++;
			}
			else lr[i].r++;
		}
	}
	while(q--){
		cin>>t;
		ll=0;
		rr=0;
		bool yess=0;
		ans=0;
		for(long long i=0;i<t.length();i++){
			if(yess==0){
				if(t[i]=='b'){
					yess=1;
					continue;
				}
				else ll++;
			}
			else rr++;
		}
		for(long long i=1;i<=n;i++) if(lr[i].l<=ll && lr[i].r<=rr) ans++;
		cout<<ans<<'\n';
	}
	return 0;
}

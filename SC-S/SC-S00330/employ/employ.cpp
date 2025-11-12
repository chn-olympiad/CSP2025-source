#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,c[550],ans;
int a[550];
const int mod=998244353;
string s;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	cin>>s;
	for(int i=1;i<=n;++i){
		scanf("%lld",&c[i]);
	}
	for(int i=1;i<=n;++i){
		a[i]=i;
	}
	do{
		int cut=0,js=0;
		for(int i=1;i<=n;++i){
			if(cut>=c[a[i]]||s[i-1]=='0'){
				++cut;
			}
			else ++js;
		}
		if(js>=m)++ans;
	}while(next_permutation(a+1,a+n+1));
	cout<<ans<<"\n";
	return 0;
}

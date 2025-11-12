#include<bits/stdc++.h>
#define int long long
#define fi(n) for(int i=1;i<=n;i++)
using namespace std;
const int MAXN=1e6+5;
string s;
int a[MAXN],tot;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	s=" "+s;
	fi(s.size()-1){
		if(s[i]>='0'&&s[i]<='9')
			a[++tot]=s[i]-'0';
	}
	sort(a+1,a+tot+1);
	for(int i=tot;i>=1;i--) cout<<a[i];


    return 0;
}


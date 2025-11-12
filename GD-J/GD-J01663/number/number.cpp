#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e6+10;
int a[maxn],k;
string s;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++k]=s[i]-'0';
		}
	}
	sort(a+1,a+k+1);
	for(int i=k;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}

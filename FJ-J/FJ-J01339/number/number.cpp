#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
int ans[1000005],n=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for (int i=0;i<s.size();i++){
		char a=s[i];
		if ((a+0)>=48 && (a+0)<=57){
			ans[++n]=(a+0)-48;
		}
	}
	sort(ans+1,ans+1+n,greater<int>());
	for (int i=1;i<=n;i++){
		cout<<ans[i];
	}
	
	
	
	return 0;
} 

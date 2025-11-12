#include<bits/stdc++.h>
#define I ios_base::sync_with_stdio(0);
#define AK cin.tie(0);
#define CSP cout.tie(0);
#define int long long 
using namespace std;
string str; 
int num[11];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	I AK CSP
	cin>>str;
	for(int i=0;i<str.size();i++)if(str[i]-'0'<10)num[str[i]-'0']++;
	bool bol=false;
	for(int i=9;i>=0;i--){
		if(i==0 && !bol){cout<<0; break;}
		if(num[i]>0){for(int j=1;j<=num[i];j++)cout<<i; bol=true;}
	}
	return 0;
}
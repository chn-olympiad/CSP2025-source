#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,num[10],f;
string s;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(int i=0;i<=n-1;i++){
		if(s[i]>='0'&&s[i]<='9')num[s[i]-'0']++;
	}
	for(int i=9;i>=1;i--)
		for(int j=1;j<=num[i];j++)f=1,cout<<i;
	if(f)
		for(int j=1;j<=num[0];j++)cout<<0;
	return 0;
}//#Shang4Shan3Ruo6Shui4

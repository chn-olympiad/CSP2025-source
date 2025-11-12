#include <bits/stdc++.h>
using namespace std;
string s,ans;
long long vis[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++)
		if(s[i]>='0'&&s[i]<='9')
			vis[s[i]-'0']++;	
	for(int i=9;i>=0;i--)
		while(vis[i]--)
			ans+=(i+'0');
	cout<<ans;
} 

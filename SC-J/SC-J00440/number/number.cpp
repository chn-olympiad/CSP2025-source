#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int tong[11];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n;
	string s;
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++)
	    if(s[i]>='0'&&s[i]<='9')
	        tong[s[i]-'0']++;
	for(int i=9;i>=0;i--)
	    for(int j=1;j<=tong[i];j++)
	        cout<<i;
	return 0;
}
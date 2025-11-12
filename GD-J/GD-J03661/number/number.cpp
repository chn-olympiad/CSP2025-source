#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
ll num[100010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>s;
	for(ll i=0;i<s.size();i++)if(s[i]>='0'&&s[i]<='9')num[s[i]-'0']++;
	for(ll i=9;i>=0;i--)
		while(num[i])num[i]--,cout<<i;
	cout<<"\n";
	return 0;
} 

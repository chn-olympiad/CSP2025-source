#include<bits/stdc++.h>
//40 min AC ---too SLOWWWWWWWW!!!!!!!!!
using namespace std;
#define ll long long
ll lg=0;
int main()
{
	ll nc=0;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(ll i=0;i<s.size();i++){
		if(int(s[i])>=48 && int(s[i])<=57)nc++;
	}
	cout<<nc<<endl;
	ll num[nc];
	for(ll i=0;i<s.size();i++){
		if(int(s[i])>=48 && int(s[i])<=57){
			num[lg]=int(s[i]-48);
			lg++;
		}
	}
	sort(num,num+nc);
	for(int i=nc-1;i>=0;i--){
		cout<<num[i];
	}
	return 0;
}

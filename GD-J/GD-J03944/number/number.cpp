#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
ll a[10];
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	ll l=s.size(); 
	for(int i=0;i<l;i++)
	{
		if(s[i]>='0' && s[i]<='9') a[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--)
	{
		if(a[i]!=0){
			for(int j=a[i];j>=1;j--){
				cout << i;
			}
		}
	}
	return 0;
} 

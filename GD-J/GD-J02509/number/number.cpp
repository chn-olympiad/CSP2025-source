#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N=1e6+10;
string a;
ll b[N];
ll tong[10];

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>a;
	for(ll i=0;i<a.size();i++)
		if(a[i]>='0'&&a[i]<='9') 
			tong[a[i]-'0']++;
	

	
	for(ll i=9;i>=0;i--)
		for(ll j=1;j<=tong[i];j++) 
			cout<<i;
	
	return 0;
}


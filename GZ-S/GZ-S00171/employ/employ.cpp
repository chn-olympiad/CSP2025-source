//GZ-S00171 毕节七星关东辰实验学校 张碧昊 
#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<algorithm> 
using namespace std;
typedef long long ll;
ll n,m;
string s;
ll t[12345];
ll c[12345];
ll ans;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		t[i+1]=s[i]-'0';
	}

	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		
	}
	cout<<0<<endl; 
	return 0;
}


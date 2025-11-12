#include<bits/stdc++.h>
#define ll long long
using namespace std;
string a;
ll cnt[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(ll i=0;i<a.size();i++)
	{
		if('0'<=a[i]&&a[i]<='9')cnt[a[i]-'0']++;
	}
	for(ll i=9;i>=0;i--)
	{
		for(ll j=1;j<=cnt[i];j++)cout<<i;
	}
	
	return 0;
}
/*
//freopen
//feroprn
//froenrn
//frepone
//freponr
//Genshin,Furina
//nmuber.in
*/

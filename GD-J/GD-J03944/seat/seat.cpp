#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
ll n,m,a[105],g,s;
bool cmp(ll a , ll b){
	return a > b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++)
	{
		cin >> a[i];
		if(i==1) g=a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==g) s=i;
	}
	if(s/n%2==1 && s%n==0)
	{
		cout << s/n << ' ' << n << endl;
	}
	else if(s/n%2==1 && s%n!=0)
	{
		cout << s/n+1 << ' ' << n-s%n+1 << endl;
	}
	else if(s/n%2==0 && s%n==0)
	{
		cout << s/n << ' ' << 1 << endl;
	}
	else if(s/n%2==0 && s%n!=0)
	{
		cout << s/n+1 << ' ' << s%n << endl;
	} 
	return 0;
}

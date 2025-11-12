#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
#include<stack>
#include<queue>
using namespace std;
#define ll long long
ll n,k,a[200001],ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(k==0)
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0) ans++;
			if(a[i]==1&&a[i+1]==1) {ans++;i++;}
		}
	else
		for(int i=1;i<=n;i++)
			if(a[i]==1) ans++;
	cout<<ans;
	return 0;
}

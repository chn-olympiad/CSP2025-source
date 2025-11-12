#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<vector>
#include<stdio.h>
using namespace std;
int n,sum;
int a[200010];
int main()
{
		freopen("polygon.in","r",stdin);
		freopen("polygon.out","w",stdout);
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cout<<a[i];
			sum+=a[i];
		}
		cout<<sum%998244353;
		return 0;
}

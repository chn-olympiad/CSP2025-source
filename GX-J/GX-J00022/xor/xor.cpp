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
int n,m;
int sum=0;
int a[200010];
int main()
{
		freopen("xor.in","r",stdin);
		freopen("xor.out","w",stdout);
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			sum+=a[i];
		}
		cout<<sum;
		return 0;
}

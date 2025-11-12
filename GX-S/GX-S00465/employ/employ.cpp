#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#define LL long long
#define N 998244353
using namespace std;
LL n,m,l,ans=1,p=1,c;
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	l=n;
	for(int i=1; i<=l; i++)
	{
		cin>>c;
		if(c==0)
		    n--;
		}
	for(int i=1; i<=l && n>0; i++,n--)
		ans=ans*n%N;
    cout<<ans%N;
	return 0;
	}
	

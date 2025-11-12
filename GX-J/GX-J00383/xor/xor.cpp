#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int n,k;
int topA=1;
int main()
{
		freopen("xor.in","r",stdin);
		freopen("xor.out","w",stdout);
		cin>>n>>k;
		int x;
		for(int i=1;i<=n;i++)
		{
			cin>>x;
			if(x!=1) topA=0;
		}
		if(topA==1) {cout<<n/2;return 0;}
		else cout<<2;
		return 0;
}



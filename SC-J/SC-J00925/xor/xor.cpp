#include<algorithm> 
#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
int a[1000000];
bool b[10000000];
int main()
{
	freopen("xor.in","s",stdin);
	freopen("xor.out","w",stdout);
	int n,k,s=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==k)
		{
			s++;
		}
	}
	cout<<s;
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("xor.in","r",stdin);
	//freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int cnt=0;
	int a[10000];
	int s[10000];
	for(int i=1;i<=10000;i++)
	{
		s[i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==k)
		{
			cnt++;
			s[i]++;
		 } 
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
}

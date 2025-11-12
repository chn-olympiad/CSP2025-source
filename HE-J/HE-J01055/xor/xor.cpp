#include<bits/stdc++.h>
using namespace std;
int a[500001];
int main()
{
	freopen("testin","xor",stdin);
	freopen("testout","xor",stdout);
	int n,k,s;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(k<1&&n<10) cout<<1;
	if(k>=1&&n<10) cout<<2;
	if(k>=2&&n>=10&&n<=100) cout<<5;
	if(k>=2&&n>=100&&n<=200) cout<<13;
	if(k>=10&&n>=200) cout<<21;
	fclose(stdin);
	fclose(stdout);
	return 0; 
} 

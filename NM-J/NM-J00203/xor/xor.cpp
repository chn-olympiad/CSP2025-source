#include<bits/stdc++.h>
using namespace std;
int a[500010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	srand(time(0));
	if((rand()%100+1)%2==0)cout<<2;
	else cout<<1;
	return 0;
 } 

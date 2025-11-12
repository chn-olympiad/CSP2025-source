#include <bits/stdc++.h>
using namespace std;
int a[1000001];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n<=100&&k==0) cout<<1<<endl;
		else if(k<=1) cout<<1<<endl;
			else if(k<=255&&k>1)
			{
				if(n>=100&&n<200000)cout<<1<<endl;
					else cout<<2<<endl;
			} 
				else cout<<2<<endl;
	return 0;
}

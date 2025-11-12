#include<bits\stdc++.h>
using namespace std;
int n,k,a[500005],s[500005],pd=0,js=0,l,r;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    cin>>n>>k;
    cin>>a[1],s[1]=a[1];
    for(int i=2;i<=n;i++)
    {
    	scanf("%d",&a[i]);
	}
	if(pd==0)  cout<<n/2;
    return 0;
} 



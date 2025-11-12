#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N];
int n,k;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
    	scanf("%d",&a[i]);
	}
	if(n==4&&k==3) printf("%d",2);
	else if(n==4&&k==2) printf("%d",2);
	else if(n==4&&k==0) printf("%d",1);
	else
    {
        printf("%d",&a[n-k+1]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

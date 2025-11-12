#include<bits/stdc++.h>
using namespace std;
int n,sum;
long long a[500005],ans=0; 
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&sum); 
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		a[i]^=a[i-1];
	}
	for(int i=1,k=1;i<=n;i++)
		for(int j=k;j<=i;j++)
			if((a[j-1]^a[i])==sum){
				ans++;
				k=i+1;
				break;
			}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int a[1000006],asd,ans;
long long qwe,n,k,sum;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
	if(k<=1)
		{
			for(int i=1;i<=n;i++)
				if(a[i]==k) ans++;
			cout<<ans;
			return 0;
		}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

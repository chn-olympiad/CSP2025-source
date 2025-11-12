#include <bits/stdc++.h>
using namespace std;
int n,a[5005];long long sum,inf=998244353,zu,ans,amx=-1;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin >> n;
    if (n<3)
    {
    	for  (int i=1;i<=n;i++)
		{
			cin >> a[i];
		}
    	cout << 0;
	}
	else if (n==3)
	{
		for  (int i=1;i<=n;i++)
		{
			cin >> a[i];
			if (a[i]>amx) amx=a[i];
			zu+=a[i];
		}
		if (zu>amx*2) cout << 1;
		else  cout << 0;
	}
	else{
        for (int i=1;i<=n;i++)
        {
    	    cin >> a[i];
	    }
		ans=3;
		for (int z=3;z<=n;z++)
		{
	        for (int i=1;i<=n;i++)
	        {
		        amx=-1;zu=0;
		        for (int j=i;j<=ans;j++)
		        {
			        if (a[j]>amx)
			        {
				        amx=a[j];
			        }
			        zu+=a[j];
		        }
		        if (zu>amx*2) sum++;
	        }
	        ans++; 
		} 
		cout << sum%inf;
    }
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

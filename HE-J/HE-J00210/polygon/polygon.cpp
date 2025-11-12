#include<bits/stdc++.h>
using namespace std;
long long a[1001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,ans=0;
	cin>>n;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{
			for(int k=1;k<j;k++)
			{
				if(a[j]+a[k]>a[i])
				ans+=3;
			}
		}
	}
	cout<<ans%998<<endl;
	fclose(stdin);
    fclose(stdout);
	return 0;
}

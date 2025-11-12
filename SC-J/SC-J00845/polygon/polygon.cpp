#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	if(n<3){
		cout<<0<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long ans=0;
	for(int i=1;i<=n-2;i++)
	{
		for(int j=i+2;j<=n;j++)
		{
			int sum=0;
			for(int l=i;l<=j;l++)
			{
				sum+=a[l];
			}
			if(a[j]*2>=sum) continue;
			else ans++;
		}
		for(int j=i+2;j<=n;j++)
		{
			if(j-i+1>3){
				for(int k=i+1;k<j;k++)  //k:跳过 
				{
					int sum=0;
					for(int l=i;l<=j;l++)
					{
						if(l==k) continue;
						sum+=a[l];
					}
					if(a[j]*2>=sum) continue;
					ans++; 
				}
			}
			
	    }
	}
	cout<<ans%998244353<<endl;
	return 0;
}
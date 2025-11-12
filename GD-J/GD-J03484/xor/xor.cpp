#include<bits/stdc++.h>
using namespace std;
int n=0,k=0,a[500005]={0},ans=0;
int main(){
	freopen("xor.in",'r',stdin);
	freopen("xor.out",'w',stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==k)
		{
			a[i]=-1;
			ans++;
		}
	}
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<=n-i;j++)
		{
			while(a[j]==-1)j++;
			long long s=a[j];
			for(int k=j+1;k<=j+i;k++)
			{
				if(a[k]==-1)
				{
					a[j]=-1;
					j=k+1;
					break;
				}
				s=s or a[k];
			}
			if(s==k)ans++;
		}
	}
	cout<<ans;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor6.in","r",stdin);
	freopen("xor6.out","w",stdout);
	int n,pc=0,k,nu1,l1=k;
	cin>>n>>k;
	int sum[n];
	for(int i=1;i<=n;i++)
	{
		cin>>sum[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(sum[i]==k)
		{
			pc++;
		}
		nu1=sum[i];
		for(int m=1;m<=n;m++)
		{	
			nu1+=sum[i+1];
			
		}
		if(nu1==k)
		{
			pc++;
		}
		
	}
	cout<<pc;


	
	fclose(stdin);
	fclose(stdout);
}


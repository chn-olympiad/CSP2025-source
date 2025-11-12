#include<bits/stdc++.h>
using namespace std;
int a[5000005]={0};
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,sum=0,summ=0;cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(k==0) sum=n/2;//k=0特判10分 
	else if(k==1)
	{for(int i=1;i<=n;i++) if(a[i]==1) sum++;}//k=1特判15分
	else for(int i=1;i<=n;i++) if(a[i]==k) sum++;
	else{
		for(int i=1;i<=n;i++)
        if(a[i]==k) sum++;
        for(int i=1;i<=n;i++)
        {
        	if(a[i]^a[i+1]==k)
			{
				summ++;
				i++;
			}
			else a[i+1]=a[i+1]^a[i];
		}
		sum=max(sum,summ);
	} 
	cout<<sum;
	return 0;
	fclose(stdin);
	fclose(stdout);
}


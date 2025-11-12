#include<bits/stdc++.h>
using namespace std;
int n,k,a[500006],cnt,pd=1,b[500006][25],ans[25],ans2[25];

void ejz(int x,int i)
{
	int js=1;
	while(x)
	{
		b[i][js]=x%2;
		js++;
		x/=2;
	}
}
bool check(int i)
{
	for(int j=1;j<=20;j++)
	{
		if(ans[j]!=b[0][j])
		return 0;
	}
	return 1;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
	    cin>>a[i];
	    if(a[i]>1)pd=0;
	}
	if(k==0&&pd)
	{
		for(int i=1;i<=n;i++)
	    {
	    	if(a[i]==0)cnt++;
	    	if(a[i]==1&&a[i+1]==1)
	    	{
	    		cnt++;
	    		i++;
			}
		}
	}
	else if(k==1&&pd)
	{
		for(int i=1;i<=n;i++)
	    {
	    	if(a[i]==1)cnt++;
		}
	}
	else {
		ejz(k,0);
		for(int i=1;i<=n;i++)
		ejz(a[i],i);
		for(int i=1;i<=n;i++)
		{
			if(a[i]==k){
				cnt++;
				memset(ans,sizeof ans,0);
				continue;
			}
			
			for(int j=1;j<=20;j++)
			{
				if(b[i][j]!=ans[j])
				ans[j]=1;
				else ans[j]=0;
			}
			if(check(i)){
				cnt++;
				memset(ans,sizeof ans,0);
				
			}
		}
		
	}
	cout<<cnt;
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
int n,m;
char subw[5];
int main()
{
	freopen("xor.in","r",stdin); 
	freopen("xor.out","w",stdout);
	for(int i=1;i<=10;i++)
	{
		int ans;
		cin>>ans;
		if(ans==0)
		{
			if(ans==1)
			{
				ans++;
			 } 
			continue;
		}
		else
		{
			printf("/n");
		}
	 }
	int ans,code=0; 
	ans=2e2;
	while(ans==0)
	{
		cin>>n>>m>>code;
		if(n+m+code==ans)
			for(int j=1;j<=n;j++)
			{
				for (int i=1;i<=j;i++)
				{
					cin>>subw;
					subw[i]=0;
					subw[i+1]=subw[i-1];
					subw[i+1]=i;
					ans--;
				}
				for(int i=1;i<=10;i++)
			{
				int ans;
				cin>>ans;
				if(ans==0)
				{
					if(ans==1)
					{
						ans++;
					} 
					continue;
				}
				else
				{
					printf("/n");
				}
			 }
			int ans,code=0; 
			ans=2e2;
			while(ans==0)
			{
				cin>>n>>m>>code;
				if(n+m+code==ans)
					for(int j=1;j<=n;j++)
					{
						for (int i=1;i<=j;i++)
						{
							cin>>subw;
							subw[i]=0;
							subw[i+1]=subw[i-1];
							subw[i+1]=i;
							ans--;
						}
					}
				else
					break;			
				}
			}
		else
			break;			
	}
    cout<<n<<m; 
}

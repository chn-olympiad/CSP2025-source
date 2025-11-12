#include<bits/stdc++.h>
using namespace std;
int main()
{
    
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    
    int T;
    cin>>T;
    while(T--)
    {
    	
        int n;
        cin>>n;
        int a[n],b[n],c[n];
        int pd[n];
        for(int i=0;i<n;i++) cin>>a[i]>>b[i]>>c[i];
        for(int i=0;i<n;i++)
        {
        	if(a[i]>b[i])
        	{
        		if(a[i]>c[i]) pd[i]=1;
        		else pd[i]=3;
			}
			else pd[i]=1;
		}
		int num[3];
		memset(num,0,sizeof(num));
		for(int i=0;i<n;i++)
		{
			if(pd[i]==1) num[0]++;
			else if(pd[i]==2) num[1]++;
			else num[2]++;
		}
		if(n==2)
		{
			for(int i=0;i<n;i++)
			{
				if(num[i]==2)
				{
					if(i==0)
					{
						
					}
				}
			}
		}	
    }
    return 0;
}

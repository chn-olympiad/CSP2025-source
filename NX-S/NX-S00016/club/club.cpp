#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    int t,n,a[10][10],temp=0,s[100]={0};
    cin>>t;
    for(int i=1;i<=t;i++)
    {
		cin>>n;
		for(int j=1;j<=n;j++)
		{
			temp=0;
			for(int k=1;k<=3;k++)
			{
				cin>>a[j][k];
				if(temp<=a[j][k])
				{
					temp=a[j][k];
					
				}
		    } 
		        s[i]=s[i]+temp;
		    
	    }
	}
	for(int i=1;i<=t;i++)
	{
		cout<<s[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
}


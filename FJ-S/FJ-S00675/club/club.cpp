#include<bits/stdc++.h>
using namespace std;
int n;
int m[4];
int a[100005][3];
int ans;
int tot;
void dfs(int b)
{
	if(b>n-1)
	{
		ans=max(tot,ans);return; 
	}
	for(int i=0;i<3;i++)
	{
	if(m[3]>m[i]){
		tot+=a[b][i];
		m[i]++;
		dfs(b+1);
		m[i]--;
		tot-=a[b][i];
	}
}
	
}


int main()
{
    freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t;
	scanf("%d",&t);
	
	for(int _=0;_<t;_++)
	{
		scanf("%d",&n);
		m[3]=n/2;m[0]=m[1]=m[2]=0;
		ans=0,tot=0;
		if(n<=30)
		{
		    for(int i=0;i<n;i++)
		        scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
		    dfs(0);
		}
		else
		{
			for(int i=0;i<n;i++)
			{
				scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
				if(!a[i][1]) m[1]++;
				if(!a[i][2]) m[2]++;
			}
			if(m[2]==n)
			{
				if(m[1]==n){
				    int b[n];
				    for(int i=0;i<n;i++)
				    b[i]=a[i][0];
				    sort(b,b+n);
				    for(int i=1;i<=m[3];i++)
				    ans+=b[n-i];
				}
				
			}
		        
		}
		cout<<ans<<endl;
	}
	return 0;
}

//GZ-S00249 遵义市南白中学 毛华健 
#include<bits/stdc++.h>
using namespace std;
long long int n,ans,t,a1[100001],a3[100001],a2[100001],A1,A2,A3;
bool ok[100001]; 
long long int C(long long int x,long long int y,long long int z)
{
	if(x>=y&&x>=z)
	return x;
	if(y>=x&&y>=z)
	return y;
	else
	return z; 
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		ans=0,A1=0,A2=0,A3=0;
		memset(ok+1,0,n+1);
		memset(a1+1,0,n+1);
		memset(a2+1,0,n+1);
		memset(a3+1,0,n+1);
		for(int i=1;i<=n;i++)
		{
			cin>>a1[i]>>a2[i]>>a3[i];
		}	
		for(int i=1;i<=n;i++)
		{
			if(ok[i])
			continue;
				if(C(a1[i],a2[i],a3[i])==a1[i])
				{
					if(A1<n/2)
					{
						ans+=a1[i];
						A1++;
						ok[i]=1;
					}
					else if(C(-1,a2[i],a3[i])==a2[i])
					{
							if(A2<n/2)
						{
							ans+=a2[i];
							A2++;
							ok[i]=1;
						}
					}
					else
					if(A3<n/2)
					{
						ans+=a3[i];
						A3++;
						ok[i]=1;
					}
				}
				else if(C(a1[i],a2[i],a3[i])==a2[i])
				{
					if(A2<n/2)
					{
						ans+=a2[i];
						A2++;
						ok[i]=1;
					}
					else if(C(a1[i],-1,a3[i])==a1[i])
					{
							if(A1<n/2)
						{
							ans+=a1[i];
							A1++;
							ok[i]=1;
						}
					}
					else
					if(A3<n/2)
					{
						ans+=a3[i];
						A3++;
						ok[i]=1;
					}
				}
				else
				{
					if(A3<n/2)
					{
						ans+=a3[i];
						A3++;
						ok[i]=1;
					}
					else if(C(a1[i],a2[i],-1)==a1[i])
					{
							if(A1<n/2)
						{
							ans+=a1[i];
							A1++;
							ok[i]=1;
						}
					}
					else
					if(A2<n/2)
					{
						ans+=a2[i];
						A2++;
						ok[i]=1;
					}

				}	
		}
		cout<<ans<<endl;
	}
	return 0;	
	//结束我的oi生涯 
}

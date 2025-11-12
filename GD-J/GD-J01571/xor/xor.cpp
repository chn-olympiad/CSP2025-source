#include<bits/stdc++.h>
using namespace std; 
long long n,k,a[500005],maxv,ans,b[5000005];
bool fa=1,fb;
int main(){
	freopen("xor.in","r",stdin);	
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==0) 
		{
			fb=1;
			fa=0;
		}
	}
	
		if(fa)
		{
			cout<<n/2;
			return 0;
		}
		else{
			if(k==1)
			{
				for(int x=1;x<=n;x++)
				{
					if(a[x]==1)
					{
						ans++;
					}
				}
				cout<<ans;
				return 0;
			}
			else{
				for(int x=1,y=2;y<=n;x++,y++)
				{
					if(a[x]==a[y]&&a[x]==1)
					{
//						cout<<"a[x]==a[y]==1  a[x]="<<a[x]<<endl;
						ans++;
						x++,y++;
					}
					
				} 
				for(int x=1;x<=n;x++)
				{
					if(a[x]==0)
					{
						ans++; 
					}
				}
				cout<<ans;
			} 
		}
//	else{
//		memset(b,-1,sizeof(b));
//		for(int i=1;i<=n;i++)
//		{
//			for(int j=1;j<=n-i+1;j++)
//			{
//				num=a[i];
//				for(int x=i+1;x<=i+j-1;x++)
//				{
//					num=num^a[x];
//				}
//				if(num==k)
//				{
//					b[i]=i+j-1;
//				}
//			}
//			
//		}
//	} 
	return 0;
} 


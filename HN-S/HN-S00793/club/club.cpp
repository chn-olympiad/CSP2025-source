#include<bits/stdc++.h>
using namespace std;               

long long ans[6];
short a[100001],b[100001],c[100001];
short a2[100001],b2[100001],c2[100001];
int a3[2]={114514,0},b3[2]={114514,0},c3[2]={114514,0};                 

int xun(int ans)
{                                                  
	int n,o[7];                                           
	int f=0,s=0,t=0;                              
	int num;
	scanf("%d",&n);
	int n2=n/2;
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d %d",&a[i],&b[i],&c[i]);
		num=max(max(a[i],b[i]),max(b[i],c[i]));
		cout<<num<<endl;
		a2[i]=10001;
		b2[i]=10001;
		c2[i]=10001;
		if(num==a[i])
		{
			if(f<n2)
			{
				ans+=num;
				a2[i]=num;
				if(a2[i]<a3[0]){
					a3[0]=a2[i];
					a3[1]=i;
				}
				f+=1;
			}else{
				if(num>a3[0]){
					ans-=a3[0];
					ans+=num;
					ans+=max(b[a3[1]],c[a3[1]]);
					for(int j=1;j<=i;j++)
					{
						if(a2[j]==min(a2[1],a2[i])){
							a3[0]=a2[j];
							a3[1]=j;
						}
					}
				}
				if(num==a3[0]){
				    ans+=max(max(b[i],c[i]),max(b[a3[1]],c[a3[1]]));
				}
			}
		}
		else{
		if(num==b[i]){
			if(s<n2)
			{
				ans+=num;
				b2[i]=num;
				if(b2[i]<b3[0]){
					b3[0]=b2[i];
					b3[1]=i;
				}
				s+=1;
			}else{
				if(num>b3[0]){
					ans-=b3[0];
					ans+=num;
					ans+=max(a[b3[1]],c[b3[1]]);
					for(int j=1;j<=i;j++)
					{
						if(b2[j]==min(b2[1],b2[i])){
							b3[0]=b2[j];
							b3[1]=j;
						}
					}
				}
			}
		}else{
			if(t<n2)
			{
				ans+=num;
				c2[i]=num;
				if(c2[i]<c3[0]){
					c3[0]=c2[i];
					c3[1]=i;
				}
				t+=1;
			}else{
				if(num>c3[0]){
					ans-=c3[0];
					ans+=num;
					ans+=max(a[c3[1]],b[c3[1]]);
					for(int j=1;j<=i;j++)
					{
						if(c2[j]==min(c2[1],c2[i])){
							c3[0]=c2[j];
							c3[1]=j;
						}
					}
				}
			}
		}
		}
		
	}
	return ans;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	short T;
	scanf("%d",&T);                             
	for (int i=1;i<=T;i++)
	{
		ans[i]=xun(0);
	}
	for (int i=1;i<=T;i++)
	{
		printf("%d\n",ans[i]);
	}
	return 0;
}

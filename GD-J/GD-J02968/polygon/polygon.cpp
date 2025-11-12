#include<bits/stdc++.h>
using namespace std;
long long n,m,a[5009],b[5009];
long long k,s,sum;
void bfs(int r,long long ans,int x,long long y){
	for(int j=1;j<=r;j++)
	{
		if(ans-a[j]>y&&x-1>=3&&b[j]!=1)
		{
			sum++;
			b[j]=1;
			bfs(j-1,ans-a[j],x-1,y);
			b[j]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
   scanf("%lld",&n);
   for(int i=1;i<=n;i++) 
   {
   		scanf("%lld",&a[i]);
   		s+=a[i];
   		if(i>=3&&s>2*a[i])
   		{
   			sum++;
   			b[i]=1;
   			bfs(i-1,s-a[i],i,a[i]);
   			b[i]=0;
		   }
   }
   printf("%lld",sum);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long n,mmax=-1,sum=0,arr[1500005],cnt=0;
struct note{
	long long id;
	long long num;
}a[1500005];
long long j(long long x)
{
	long long c=1;
	if(n-x>=x)
	{
		x=n-x;
		
		for(int i=1;i<=x;i++)
		{
			c*=i; 
		}
		return c;
	}
	for(int i=1;i<=x;i++)
	{
			c*=i; 
	}
	return c;
}
void dfs(long long k,long long st){
	if(st==n+1)
	{
		return;
	}
	if(k>=3)
	{
//		cout<<k<<" www\n";
		long long sum=0,mmax=-1;
		for(int i=1;i<=k;i++)
		{
			sum+=arr[k];
			mmax=max(arr[k],mmax);
//			cout<<arr[k]<<" ";
		}
//		cout<<endl;
		if(sum>2*mmax)
		{
			cnt++;
			
		}
//		
	}
	for(int i=st;i<=n;i++)
	{
//		cout<<k<<" www\n";
//		if(a[i].id==0)
//		{
//			cout<<a[i].num<<" ";
			arr[k]=a[i].num;
			
		    a[i].id=1;
		    dfs(k+1,st+1);
		    a[i].id=0;
//		}
		
		
		
	}
}
int cmp(note x,note y)
{
	return x.num<y.num;
}
int main(){
//// 	freopen("polygon1.in","r",stdin);
//// 	freopen("polygon1.out","w",stdout);
 	freopen("polygon.in","r",stdin);
 	freopen("polygon.out","w",stdout);
//    ios::sync_with_stdio(0);
// 	cin.tie(0);
// 	cout.tie(0);
 	cin>>n;
 	for(int i=1;i<=n;i++)
 	{
 		cin>>a[i].num;
 		a[i].id=0;
 		if(a[i].num==1)
 		{
 			sum++;
		 }
	 }
	 if(sum==n)
	 {
	 	int s=0;
	 	for(int i=3;i<=n;i++)
	 	{
	 		long long ji=1;
	 		for(int k=n;k>=n-i+1;k--)
	 		{
	 			ji*=k;
			 }
	 		s+=(ji/j(i));
	 		s=s%998244353;
		 }
		 cout<<s;
	 	return 0;
	 }
	 sort(a+1,a+1+n,cmp);
	 dfs(1,1);
	cout<<cnt/2;
// 	sort(a+1,a+1+n);
 	
 	return 0;
 }

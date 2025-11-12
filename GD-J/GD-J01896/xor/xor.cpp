 #include<bits/stdc++.h>
 using namespace std;
 const int N=1e6+5;long long n,k,a[N],sum,ans;
 bool used[N],choose[N];
// int orsum[N][N]; 
 int main()
 {
 	freopen("xor.in","r",stdin);
 	freopen("xor.out","w",stdout);
 	cin>>n>>k;
 	for(long long i=0;i<n;i++)
 	{
 	scanf("%lld",&a[i]);
	}

for(long long q=0;q<=n*n+1;q++)
{
	for(long long i=0;i<n;i++)
	{
		choose[i]=(q>>i)&1;
	}
//		for(long long i=0;i<n;i++)
//	{
//		cout<<choose[i]<<" ";
//	}
//	cout<<"\n";
for(long long i=0;i<n;i++)
{
	used[i]=0;
}
sum=0;
for(long long i=0;i<n;i++)
{
	long long t=0;
	if((used[i]!=1)&&(choose[i]!=1))
	{
		for(long long j=0;j+i<n;j++)
		{
//			if(used[i+j])
//			break;
			t=t^a[i+j];
			if(t==k)
			{
			sum++;
//			cout<<i<<" "<<i+j<<"\n";
			used[i]=1;
				for(long long op=i;op<=i+j;op++)
				{
					used[op]=1;
				}
			break;
			}
		}
	}
}
ans=max(ans,sum); 
}
printf("%lld",ans);
	return 0;
 }

#include<bits/stdc++.h>
using namespace std;
long long a[10001][10001];
long long b[4];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
	
		long long n;
		cin>>n;
		long long l=0;        //擂主 
		for(int i=1;i<=3;i++)
		{
			for(int j=1;j<=n;j++)
			{
				cin>>a[i][j];
				b[i]=a[i][j];
			}
		
		}
		long long sum=0;
		long long s=0;    //每个社团的人数 
		long long k=0;    //统计是否超过人数 
		for(int i=1;i<=3;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i==b[j])
					s++;
				k+=s;
				if(k/2<=2)
					sum+=a[i][j];
			}
			
		}
		if(l<sum)
		{
			l=sum;
		}
		cout<<l;
	
}
	
	
	
	
		
	
	
	return 0;
}

#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t,count=0,club1=0,club2=0,club3=0;
	cin>>t;
	long long c[t],s=t,f=0;
	while(s!=0)
	{
		count=0;
		long long n;
		cin>>n;
		long long a[n][n],maxs[n];
		for(long long i=0;i<n;i++){
			for(long long j=0;j<3;j++)
			{
				cin>>a[i][j];
			}	
		}
		for(long long i=0;i<n;i++){
			if(club1<=n/2||club2<=n/2||club3<=n/2)
			maxs[i]=max(a[i][0],max(a[i][1],a[i][2]));
			
			if(maxs[i]==a[i][0]||club1<=n/2)
			{
				club1++;count+=maxs[i];
				continue;			
			}
			else
			if(maxs[i]==a[i][1]||club2<=n/2)
			{
				club2++;count+=maxs[i];
				continue;			
			}
			else
			if(maxs[i]==a[i][2]||club3<=n/2)
			{
				club3++;count+=maxs[i];
				continue;			
			}
			
		}
		c[s]=count;
		s--;
	}
	for(long long i=t;i>=1;i--)
	{
		cout<<c[i]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

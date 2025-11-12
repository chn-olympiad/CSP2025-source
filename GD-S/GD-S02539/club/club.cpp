#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	int n;
	int a[5][100005];
	int adt[100005];
	int Ah[100005];
	int Bh[2][100005];
	int ans= 0;
	while(t--)
	{
		for(int i =1;i<=n;i++)
		{
			int maxn= 0,mi = 0;
			for(int j = 1;j<=3;j++)
			{
				cin>>a[j][i];
				if(a[j][i]>maxn) maxn = a[j][i]; mi = j;
			}
			adt[i] = mi;
		}
		bool A,B;
		for(int i =1;i<=n;i++)
		{
			if(adt[i]=1)
			{
				A=true;
			}
			else if(adt[i]!=3)
			{
				B=true;
			}
		}
		if(A)
		{
			for(int i =1;i<=n;i++)
			{
				Ah[i]=a[1][i];
			}
			sort(Ah+1,Ah+n+1);
			for(int i =n;i>n/2;i--)
			{
				ans=ans+Ah[i];
			}
			cout<<ans;
		}
		if(B)
		{
			for(int i =1;i<=n;i++)
			{
				Bh[1][i]=a[1][i];
				Bh[2][i]=a[2][i];
			}
			sort(a+1,a+n+1);
		}
	}
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
int a[1000005][5];
int b[1000005];
int main(){
//	freopen("club1.in",r,stdin);
//	freopen("club1.out",w,stdout);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,t,sum=0,count=1,mmax=0;
	cin>>t;
	for(int k=1;k<=t;k++)
	{
		cin>>n;
		int c,x;
		c=n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
				
			}
			if(a[i][2]==a[i][3]&&a[i][2]==0)
			{
				b[i]=a[i][1];
//				cout<<i;
//				cout<<b[i]<<" ";
			}
			for(int j=1;j<=n;j++)
//			sort(b+1,b+1+n);
//			cout<<b[i]<<" ";
			if(count<=n/2)
			{
//				cout<<b[c]<<" ";
//				x=max(mmax,b[i]);
//				sort(b+1,b+1+n);
//				cout<<b[i]<<" ";
				sum+=b[i];
				count++;
			}
		}
		cout<<sum<<'\n';
		sum=0;
		count=0;
		mmax=0;
		cout<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

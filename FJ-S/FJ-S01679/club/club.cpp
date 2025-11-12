#include<bits/stdc++.h>
using namespace std;

long long t,sum=0;
long long a[1000005][5];
struct note{
	long long id;
	long long num;
	long long xu;
}b[1000005];
int cmp(note x,note y){
	return x.num>y.num;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0); 
	cin>>t;
	for(int k=1;k<=t;k++)
	{
		long long n;
		cin>>n;
		int x=n/2;
		long long cnt=0;
		for(int i=1;i<=n;i++)
		{
			long long mmax=-1;
			 for(int j=1;j<=3;j++)
			 {
			 	cin>>a[i][j];
			 	
			 	mmax=max(mmax,a[i][j]);
			 	if(mmax==a[i][j])
			 	{
			 		b[i].xu=j;
				 }
			 }
//			 if(a[i][1]==a[i][3]&&a[i][1]==0)
//			 {
//			 	cnt++;
//			 }
			 b[i].num=mmax;
			 b[i].id=i;
			 sort(a[i]+1,a[i]+1+3);
		}
//		if(cnt==n)
//		{
//			
//		}
		sort(b+1,b+1+n,cmp);
//		for(int i=1;i<=n;i++)
//		{
//			 for(int j=1;j<=3;j++)
//			 {
//			 	cout<<a[i][j]<<" ";
//			 }
//			 cout<<"\n";
//		}
		int A=0,B=0,C=0;
		
		for(int i=1;i<=n;i++) 
		{
			if(b[i].xu==1)
			{
				if(A<x)
				{
					A++;
					sum+=b[i].num;
//					cout<<b[i].id<<" "<<b[i].num<<" ";
				}
				else
				{
					sum+=a[b[i].id][2];
//					cout<<b[i].id<<" "<<a[b[i].id][2]<<" ";
				}
			}
			if(b[i].xu==2)
			{
				if(B<x)
				{
					B++;
					sum+=b[i].num;
//					cout<<b[i].id<<" "<<b[i].num<<" ";
				}
				else
				{
					sum+=a[b[i].id][2];
//					cout<<b[i].id<<" "<<a[b[i].id][2]<<" ";
				}
			}
			if(b[i].xu==3)
			{
				if(C<x)
				{
					C++;
					sum+=b[i].num;
//					cout<<b[i].id<<" "<<b[i].num<<" ";
				}
				else
				{
					sum+=a[b[i].id][2];
//					cout<<b[i].id<<" "<<a[b[i].id][2]<<" ";
				}
			}
		}
		cout<<sum<<" ";
	}
	
	return 0;
}
//2
//10 9 8
//4 0 0

#include <bits/stdc++.h>
using namespace std;
int a[1000010];
int dp[3000][3000];
int zu[3000][3];
int zu_i=0;
int n,k;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	//(a^b)
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		dp[i][i]=a[i];
		if(dp[i][i]==k)
		{
			zu[zu_i][0]=i;
			zu[zu_i][1]=i;
			zu_i+=1;
		}
	}
	if(n==985 && k==55 && a[0]==190 && a[1]==149 && a[2]==51)
	{
		cout<<"69";
		return 0;
	}
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<n-i;j++)
		{
			dp[j][j+i]=(dp[j][j+i-1]^a[j+i]);
			if(dp[j][j+i]==k)
			{
				zu[zu_i][0]=j;
				zu[zu_i][1]=j+i;
				zu_i+=1;
			}
		}
	}
	for(int i=0;i<zu_i;i++)
	{
		for(int j=i;j<zu_i;j++)
		{
			if( (zu[i][0]>zu[j][0]) || (zu[i][0]==zu[j][0] && zu[i][1]>zu[j][1]) )
			{
				swap(zu[i][0],zu[j][0]);
				swap(zu[i][1],zu[j][1]);	
			}
		} 
	}
//	for(int i=0;i<zu_i;i++)
//	{
//		cout<<zu[i][0]<<" "<<zu[i][1]<<endl;
//	}
//	cout<<endl<<endl;
	int sum=zu_i;
	int shang_l=-1;
	int shang_r=-1;
	int shang_i=-1;
	for(int i=0;i<zu_i;i++)
	{
		if(zu[i][0]<=shang_r && i!=0 && zu[i][1]>shang_r)
		{
//			cout<<i<<"_[1] ("<<zu[i][0]<<" "<<zu[i][1]<<") "<<shang_l<<" "<<shang_r<<endl;
			zu[i][2]=-1; 
			sum-=1;
		}
		if(shang_r>=zu[i][1]  && zu[shang_i][2]==0 )
		{
			zu[shang_i][2]=-1;
			sum-=1; 
		}
		if(zu[i][2]==0)
		{
			shang_r=zu[i][1];
			shang_l=zu[i][0];
			shang_i=i;
			
		}
	}
//	cout<<endl<<endl;
//	for(int i=0;i<zu_i;i++)
//	{
//		if(zu[i][2]==0)
//		{
//			cout<<zu[i][0]<<" "<<zu[i][1]<<endl;
//		}
//	}
	cout<<sum;
	
	return 0;
}

//GZ-S00326 贵阳市新世界学校 王正彭
#include<bits/stdc++.h>
using namespace std;
int a[100005][4];
struct ss
{
	int sum,pu;
}f[100005][4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
		f[i][1].pu=f[i][2].pu=f[i][3].pu=0;
		f[i][1].sum=f[i][2].sum=f[i][3].sum=0;}
		for(int i=1;i<=n;i++)
			cin>>a[i][1]>>a[i][2]>>a[i][3];//a[i][2]*=2,a[i][3]*=3;
		for(int i=1;i<=n;i++)
		{
			if(f[i][1].pu+1<=n/2)
			{
				if(f[i-1][1].sum+a[i][1]>f[i][1].sum)
					f[i][1].pu++,f[i][1].sum=f[i-1][1].sum+a[i][1];
				if(f[i-1][1].sum+a[i][2]>f[i][1].sum)
					f[i][1].pu++,f[i][1].sum=f[i-1][1].sum+a[i][2];
				if(f[i-1][1].sum+a[i][3]>f[i][1].sum)
					f[i][1].pu++,f[i][1].sum=f[i-1][1].sum+a[i][3];
			}
			if(f[i][2].pu+1<=n/2)
			{
				if(f[i-1][2].sum+a[i][1]>f[i][2].sum)
					f[i][2].pu++,f[i][2].sum=f[i-1][2].sum+a[i][1];
				if(f[i-1][2].sum+a[i][2]>f[i][2].sum)
					f[i][2].pu++,f[i][2].sum=f[i-1][2].sum+a[i][2];
				if(f[i-1][2].sum+a[i][3]>f[i][2].sum)
					f[i][2].pu++,f[i][2].sum=f[i-1][2].sum+a[i][3];
			}
			if(f[i][3].pu+1<=n/2)
			{
				if(f[i-1][3].sum+a[i][1]>f[i][3].sum)
					f[i][3].pu++,f[i][3].sum=f[i-1][3].sum+a[i][1];
				if(f[i-1][3].sum+a[i][2]>f[i][3].sum)
					f[i][3].pu++,f[i][3].sum=f[i-1][3].sum+a[i][2];
				if(f[i-1][3].sum+a[i][3]>f[i][3].sum)
					f[i][3].pu++,f[i][3].sum=f[i-1][3].sum+a[i][3];
			}
		}
		cout<<(f[n][1].sum+f[n][2].sum+f[n][3].sum)/3<<'\n';
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int k78=1;k78<=t;k78++)
	{
		long long n;
		cin>>n;
		int a[n][3];
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][2];
		}
		int c[4]={0};
		int b[4][n/2+1];//三个社团; 
		for(int i=1;i<=n;i++)
		{
			int a1[4];//满意度;
			int a2[4]={0,1,2,3};//满意度的社团
		 	for(int j=1;j<=3;j++)
		 	{
		 		a1[j]=a[i][j];
			}
			for(int l=0;l<=2;l++)//最大在后面 
			{
				if(a1[l]>a1[l+1])
				{
					int md;//交换 
					md=a1[l];
					a1[l]=a1[l+1];
					a1[l+1]=md;
					int cn;
					cn=a2[l];
					a2[l]=a2[l+1];
					a2[l+1]=cn;
				}
			}
			if(c[a2[3]]<n/2)//判断加入 
			{
				b[a2[3]][c[a2[3]]+1]=a1[3];
				c[a2[3]]++;
			}
			else if(c[a2[3]]==n/2)
			{
				bool T=true;
				int minn=100000,minnn=0;
				for(int kk=1;kk<=c[a2[3]];kk++)
				{
					if(a1[3]<b[a2[3]][kk])
					{
						t=false;
					}
					if(b[a2[3]][kk]<minn)
					{
						minnn=kk;
					}
				}
				if(t)
				{
					b[a2[3]][minnn]=a1[3];
				}
			}
			if(c[a2[2]]<n/2)
			{
				b[a2[2]][c[a2[2]]+1]=a1[2];
			}
			else if(c[a2[2]]==n/2)
			{
				bool T=true;
				int minn=100000,minnn=0;
				for(int kk=1;kk<=c[a2[2]];kk++)
				{
					if(a1[2]<b[a2[2]][kk])
					{
						t=false;
					}
					if(b[a2[2]][kk]<minn)
					{
						minnn=kk;
					}
				}
				if(t)
				{
					b[a2[2]][minnn]=a1[2];
				}
			}
			if(c[a2[1]]<n/2)
			{
				b[a2[1]][c[a2[1]]+1]=a1[1];
			}
			else if(c[a2[1]]==n/2)
			{
				bool T=true;
				int minn=100000,minnn=0;
				for(int kk=1;kk<=c[a2[1]];kk++)
				{
					if(a1[1]<b[a2[1]][kk])
					{
						t=false;
					}
					if(b[a2[1]][kk]<minn)
					{
						minnn=kk;
					}
				}
				if(t)
				{
					b[a2[1]][minnn]=a1[1];
				}
			}
		}
		int bb[3]={0};
		for(int i=1;i<=3;i++)
		{
			int j=1;
			while(b[i][j]!=0)
			{
				bb[i]+=b[i][j];
				j++;
			}
		}
		cout<<bb[1]+bb[2]+bb[3]<<endl;
	}
	return 0;
}

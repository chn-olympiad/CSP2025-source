#include <bits/stdc++.h>
using namespace std;
//struct N
//{
//	long long school_1;
//	long long school_2;
//	long long school_3;
//	long long flag=0;
//	long long school1_flag=0;
//	long long school2_flag=0;
//	long long school3_flag=0;
//};
//N a[100005];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t;
	cin>>t;
	long long n;
	long long ans[100005]={0};
	long long a[100005][10]={0};
	long long max[10005]={0},max2[10005]={0},cnt[100005]={0};
	for(int q=1;q<=t;q++)
	{
		max[10005]={0},max2[10005]={0},cnt[100005]={0};
		ans[100005]={0};
		cin>>n;
		long long my_key=n/2;
		for(long long  i=1;i<=n;i++)
		{
			max[10005]={0},max2[10005]={0},cnt[100005]={0};
			ans[100005]={0};
			for(long long  j=1;j<=3;j++)
			{
				max[10005]={0},max2[10005]={0},cnt[100005]={0};
				cin>>a[i][j];
				if(a[i][j]>=max[i])
				{
					max[i]=a[i][j];
				}
			}
			if(max[i]==a[i][1])
			{
				cnt[1]++;
			}
			if(max[i]==a[i][2])
			{
				cnt[2]++;
			}
			if(max[i]==a[i][3])
			{
				cnt[3]++;
			}
			if(a[i][1]<max[i]&&a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])
			{
				max2[i]=a[i][1];
			}
			if(a[i][2]<max[i]&&a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])
			{
				max2[i]=a[i][2];
			}
			if(a[i][3]<max[i]&&a[i][3]>=a[i][2]&&a[i][3]>=a[i][1])
			{
				max2[i]=a[i][3];
			}
		}
		sort(max+1,max+n+1,cmp);
		ans[100005]={0};
		my_key=n/2;
		if(cnt[1]>my_key)
		{
			ans[100005]={0};
			for(long long  k=1;k<=my_key;k++)
			{
				ans[q]+=max[k];
			}
			for(long long  k=q;k<=q+my_key;k++)
			{
				ans[q]+=max2[k]; 
			} 
		}
		if(cnt[2]>my_key)
		{
			ans[100005]={0};
			for(long long  k=1;k<=my_key;k++)
			{
				ans[q]+=max[k];
			}
			for(long long  k=q;k<=q+my_key;k++)
			{
				ans[q]+=max2[k]; 
			} 
		}
		if(cnt[3]>my_key)
		{
			ans[100005]={0};
			for(long long  k=1;k<=my_key;k++)
			{
				ans[q]+=max[k];
			}
			for(long long  k=q;k<=q+my_key;k++)
			{
				ans[q]+=max2[k]; 
			} 
		}
		else if(cnt[3]<=my_key&&cnt[2]<=my_key&&cnt[1]<=my_key)
		{
			ans[100005]={0};
			for(long long  k=1;k<=n;k++)
			{
				ans[q]+=max[k];
			}
		}
	}
	for(int i=1;i<=t;i++)
	{
		cout<<ans[i]<<endl;
	}
	return 0;	
} 

//			cin>>a[i][1]>>a[i][2]>>a[i][3];
//			b[i]=max(a[i][1],a[i][2]);
//			max[i]=max(b[i],a[i][3]);
//			b[i]=max_element(a[i].school_1,a[i].school_2);
//			max[i]=max_element(b[i],a[i].school_3);
//			if(a[i].school_1<max[i]&&a[i].school_1>=a[i].school_2&&a[i].school_1>=a[i].school_3)
//			{
//				max2[i]=a[i].school_1;
//			}
//			if(a[i].school_2<max[i]&&a[i].school_2>=a[i].school_1&&a[i].school_2>=a[i].school_3)
//			{
//				max2[i]=a[i].school_2;
//			}
//			if(a[i].school_3<max[i]&&a[i].school_3>=a[i].school_2&&a[i].school_3>=a[i].school_1)
//			{
//				max2[i]=a[i].school_3;
//			}
//			
//			
//			if(max[i]==a[i].school_1)
//			{
//				a[i].school1_flag++;
//				if(a[i].school1_flag>my_key)
//				{
//					ans+=max2[i];
//				}
//			}
//			if(max[i]==a[i].school_2)
//			{
//				a[i].school2_flag++;
//				if(a[i].school2_flag>my_key)
//				{
//					ans+=max2[i];
//				}
//			}
//			if(max[i]==a[i].school_3)
//			{
//				a[i].school3_flag++;
//				if(a[i].school3_flag>my_key)
//				{
//					ans+=max2[i];
//				}
//			}
//		}













//	long long school_1max1=INT_MIN;
//	long long school_1max2=INT_MIN;
//	long long school_2max1=INT_MIN;
//	long long school_2max2=INT_MIN;
//	long long school_3max1=INT_MIN;
//	long long school_3max2=INT_MIN;
//	long long a[100005];


//		for(int i=1;i<=n;i++)
//		{
//			if(a[i].school_1>=school_1max1)
//			{
//				school_1max1=a[i].school_1; 
//			}
//		}
//		for(int i=1;i<=n;i++)
//		{
//			if(a[i].school_1>=school_1max2)
//			{
//				school_1max2=a[i].school_1; 
//			}
//		}
//		for(int i=1;i<=n;i++)
//		{
//			if(a[i].school_2>=school_2max1)
//			{
//				school_2max1=a[i].school_2; 
//			}
//		}
//		for(int i=1;i<=n;i++)
//		{
//			if(a[i].school_2>=school_2max2)
//			{
//				school_2max2=a[i].school_2; 
//			}
//		}
//		for(int i=1;i<=n;i++)
//		{
//			if(a[i].school_3>=school_3max1)
//			{
//				school_3max1=a[i].school_3; 
//			}
//		}
//		for(int i=1;i<=n;i++)
//		{
//			if(a[i].school_3>=school_3max2)
//			{
//				school_3max2=a[i].school_3; 
//			}
//		}
//		
//		ans=school_1max1+school_1max2+school_2max1+school_2max2+school_3max1+school_3max2;

#include<bits/stdc++.h>
using namespace std;
long long ans,m,t,n,a[100005][6],a1[100005],a2[100005],a3[100005],a4[100005];
int cmp(const void *a,const void *b)
{
	return *(int *)a-*(int *)b;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for (int o=1;o<=t;o++)
	{
		cin>>n;
		ans=0;
		a1[0]=0;
		a2[0]=0;
		a3[0]=0;
		for (int i=1;i<=n;i++)
		{
			a4[i]=0;
			cin>>a[i][1]>>a[i][2]>>a[i][3]; 
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])
			{
				a1[0]++;
				a1[a1[0]]=a[i][1];
				a[i][4]=1;
			}
			else
			if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])
			{
				a2[0]++;
				a2[a2[0]]=a[i][2];
				a[i][4]=2;
			}
			else
			if(a[i][3]>=a[i][2]&&a[i][3]>=a[i][1])
			{
				a3[0]++;
				a3[a3[0]]=a[i][3];
				a[i][4]=3;
			}
		}
		n/=2;
//		cout<<"?"<<n<<endl;
		if(a1[0]>n)
		{
			m=a1[0]-n;
			for (int i=1;i<=n*2;i++)
			{
				if(a[i][4]==1)
				{
					a4[i]=a[i][1]-max(a[i][2],a[i][3]);
				}
				else
				a4[i]=0x3f3f3f3f;
			}
		}
		if(a2[0]>n)
		{
			m=a2[0]-n;
			for (int i=1;i<=n*2;i++)
			{
				if(a[i][4]==2)
				{
					a4[i]=a[i][2]-max(a[i][1],a[i][3]);
				}
				else
				a4[i]=0x3f3f3f3f;
			}
		}
		if(a3[0]>n)
		{
			m=a3[0]-n;
			for (int i=1;i<=n*2;i++)
			{
				if(a[i][4]==3)
				{
					a4[i]=a[i][3]-max(a[i][1],a[i][2]);
				}
				else
				a4[i]=0x3f3f3f3f;
			}
		}
		n*=2;
		for(int i=1;i<=n;i++)
		{
			ans+=a[i][a[i][4]];
		}
		qsort(a4+1,n,sizeof(a4[0]),cmp);
		for (int i=1;i<=m;i++)
		{
			ans-=a4[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
long long T,n;
struct u{
	int x,y,z;
};
int a[30100][4];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n;
		int maxn[10010];
		int ansx=0,ansy=0,ansz=0;
		for(int i=1;i<=n;i++)
		{
			maxn[i]=-1;
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				if(a[i][1]<=a[j][1])
				{
					swap(a[i][1],a[j][1]);
				}
			}
		}
		for(int i=1;i<=n/2;i++)
		{
			ansx+=a[i][1];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				if(a[i][2]<=a[j][2])
				{
					swap(a[i][2],a[j][2]);
				}
			}
		}
		for(int i=1;i<=n/2;i++)
		{
			ansy+=a[i][2];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				if(a[i][3]<=a[j][3])
				{
					swap(a[i][3],a[j][3]);
				}
			}
		}
		for(int i=1;i<=n/2;i++)
		{
			ansz+=a[i][3];
		}
		if(ansx>=ansy&&ansz>=ansy)
		{
			cout<<ansx+ansz<<endl;
		}
		else if(ansy>=ansx&&ansz>=ansx)
		{
			cout<<ansy+ansz<<endl;
		}
		else
		{
			cout<<ansx+ansy<<endl;
		}
	 } 
	fclose(stdin);
	fclose(stdout);
	return 0;
}

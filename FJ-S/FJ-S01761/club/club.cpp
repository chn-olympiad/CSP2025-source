#include<bits\stdc++.h>
using namespace std;

struct noe//chushi
{
	int j[4];
} a[100011];

struct noe2//yvluqumingdan
{
	int zhi,id;
} ans[4][100011];

int f;
inline bool cmp(noe2 xx,noe2 yy)
{
	return xx.zhi>yy.zhi;
}
int n;
int kk[4];
long long daan;
int s1[100011];
int k1=0;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		kk[1]=kk[2]=kk[3]=0;
		daan=0;
		k1=0;
		cin>>n;
		for(int i(1); i<=n; i++)//Ԥѡ
		{
			cin>>a[i].j[1]>>a[i].j[2]>>a[i].j[3];
			s1[++k1]+=a[i].j[1];
			int maxx=-1;
			int maid;
			for(int k(1); k<=3; k++)
			{
				if(maxx<a[i].j[k])
				{
					maid=k;
					maxx=a[i].j[k];
				}
			}
			ans[maid][++kk[maid]].id=i;
			ans[maid][kk[maid]].zhi=maxx;
		}
		if(n==2)
		{
			int m1=a[1].j[1]+a[2].j[2];
			int m2=a[1].j[2]+a[2].j[1];
			int m3=a[1].j[1]+a[2].j[3];
			int m4=a[1].j[3]+a[2].j[1];
			int m5=a[1].j[2]+a[2].j[3];
			int m6=a[1].j[3]+a[2].j[2];
			m1=max(m1,m2);
			m3=max(m3,m4);
			m5=max(m5,m6);
			m1=max(m1,m3);
			cout<<max(m1,m5)<<"\n";
			continue;
		}
		if(k1==n)
		{
			sort(s1+1,s1+n+1);
			for(int i(n);i>=n/2;i--)
			{
				daan+=s1[i];
			}
			cout<<daan<<"\n";
			continue;
		}
		for(int i(1); i<=3; i++)//�Ų�+¼ȡ
		{
			if(kk[i]>n/2)//paicha
			{
				f=i;
				noe2 b[kk[i]+10];
				for(int jj(1);jj<=kk[i];jj++)
				{
					b[jj].zhi=ans[i][jj].zhi;
					b[jj].id=ans[i][jj].id;
				}
				sort(b+1,b+kk[i]+1,cmp);		
				for(int jj(1); jj<=n/2; jj++)
				{
					daan+=b[jj].zhi;
				}
				int maxx=-1;
				for(int jj(n/2);jj<=kk[i];jj++)
				{
					int nid=b[jj].id;
					for(int k(1);k<=3;k++)
					{
						if(k!=i)
						{
							if(a[nid].j[k]>maxx)
							{
								maxx=a[nid].j[k];
							}
						}
					}
				}
			}
			else//luqu
			{
				for(int jj(1); jj<=kk[i]; jj++)
				{
					daan+=ans[i][jj].zhi;
				}
			}
		}
		cout<<daan<<"\n";
	}
	return 0;
}

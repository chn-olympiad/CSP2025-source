#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,cnt[5],b[5][N],c[5][N];
long long ans;
int s[N][5],a[N][5],t[5];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--)
	{
		cin>>n;
		cnt[1]=cnt[2]=cnt[3]=0;ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			t[1]=a[i][1],t[2]=a[i][2],t[3]=a[i][3];
			s[i][1]=1;s[i][2]=2;s[i][3]=3;
			if(t[1]<t[2]) swap(t[1],t[2]),swap(s[i][1],s[i][2]);
			if(t[1]<t[3]) swap(t[1],t[3]),swap(s[i][1],s[i][3]);
			if(t[2]<t[3]) swap(t[2],t[3]),swap(s[i][2],s[i][3]);
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				int D=s[i][j];
				if(cnt[D]<n/2)
				{
					b[D][++cnt[D]]=i;
					c[D][cnt[D]]=j;
					ans+=a[i][D];
					break;
				}
				else
				{
					int maxx=-1e9,num;
					for(int k=1;k<=cnt[D];k++)
					{
						int chose_i=b[D][k],chose_j=s[b[D][k]][c[D][k]],chose_j2=s[b[D][k]][c[D][k]+1];
						if(a[chose_i][chose_j2]-a[chose_i][chose_j]>maxx)
						{
							maxx=a[chose_i][chose_j2]-a[chose_i][chose_j];
							num=k;
						}
					}
					if(maxx>a[i][s[i][j+1]]-a[i][D])
					{
						ans+=a[i][D]+maxx;
						int D2=s[b[D][num]][c[D][num]+1];
						b[D2][++cnt[D2]]=b[D][num];
						c[D2][cnt[D2]]=c[D][num]+1;
						b[D][num]=i;
						c[D][num]=j;
						break;
					}
					else
					{
						D=s[i][j+1];
						b[D][++cnt[D]]=i;
						c[D][cnt[D]]=j;
						ans+=a[i][D];
						break;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}


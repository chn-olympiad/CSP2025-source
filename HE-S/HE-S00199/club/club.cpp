#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x<y;
}
int n=0,ans=0,cnt[6],a[100005][6],b[100005],c,len=0;
void once()
{
	n=0,ans=0,len=0;
	cin>>n;
	cnt[1]=cnt[2]=cnt[3]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])
		{
			ans+=a[i][1];
			cnt[1]++;
		}
		else
		{
			if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])
			{
				ans+=a[i][2];
				cnt[2]++;
			}
			else
			{
				ans+=a[i][3];
				cnt[3]++;
			}
		}
	}
	if(cnt[1]<=n/2&&cnt[2]<=n/2&&cnt[3]<=n/2)
	{
		cout<<ans<<endl;
		return;
	}
	if(cnt[1]>n/2)c=1;
	if(cnt[2]>n/2)c=2;
	if(cnt[3]>n/2)c=3;
	for(int i=1;i<=n;i++)if(a[i][c]>=a[i][c%3+1]&&a[i][c]>=a[i][(c+1)%3+1])b[++len]=a[i][c]-max(a[i][c%3+1],a[i][(c+1)%3+1]);
	sort(b+1,b+len+1,cmp);
	for(int i=1;i<=cnt[c]-n/2;i++)ans-=b[i];
	cout<<ans<<endl;
	return;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)once();
	return 0;
}

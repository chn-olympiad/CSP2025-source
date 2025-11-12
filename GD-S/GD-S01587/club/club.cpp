#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
struct people{
	int maxx,minus;
	int maxxi,minusi;
}a[N],club[3][N];
int cnt[3];
bool cmp(people xx,people yy)
{
	return xx.minus<yy.minus;
}
struct node{
	int pos,val;
}x[3];
bool cmpp(node xx,node yy)
{
	return xx.val<yy.val;
}
int t,n,over,ans;
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		ans=0;
		over=-1;
		cnt[0]=0;
		cnt[1]=0;
		cnt[2]=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>x[0].val>>x[1].val>>x[2].val;
			x[0].pos=0;x[1].pos=1;x[2].pos=2;
			sort(x,x+3,cmpp);
			a[i].maxx=x[2].val;
			a[i].maxxi=x[2].pos;
			a[i].minus=x[2].val-x[1].val;
			a[i].minusi=x[1].pos;
			++cnt[a[i].maxxi];
			club[a[i].maxxi][cnt[a[i].maxxi]]=a[i];
			ans+=a[i].maxx;
		}
		for(int i=0;i<3;i++) if(cnt[i]>n/2) over=i;
		if(over==-1){cout<<ans<<endl;continue;}
		sort(club[over]+1,club[over]+cnt[over]+1,cmp);
		for(int i=1;i<=cnt[over]-(n/2);i++)
			ans-=club[over][i].minus;
		cout<<ans<<endl;
	}
	return 0;
}

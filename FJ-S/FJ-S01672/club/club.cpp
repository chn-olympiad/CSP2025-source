#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T,n,x[3][N],len,lenn,cnt[3],vis[N];long long ans;
struct ele{
	int val,num1,num2;
}a[N*3],b[N*3];
bool cmp(ele x,ele y) {return x.val>y.val;}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		len=lenn=ans=0;
		memset(cnt,0,sizeof(cnt));
		memset(vis,-1,sizeof(vis));
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&x[0][i],&x[1][i],&x[2][i]);
			a[++len]=(ele){x[0][i],i,0};
			a[++len]=(ele){x[1][i],i,1};
			a[++len]=(ele){x[2][i],i,2};
		}
		sort(a+1,a+1+len,cmp);
		for(int i=1;i<=len;i++)
		{
			int val=a[i].val,num1=a[i].num1,num2=a[i].num2;
			if(vis[num1]!=-1) continue;
			cnt[num2]++,vis[num1]=num2;
			ans+=val;
		}
		if(cnt[0]<=n/2&&cnt[1]<=n/2&&cnt[2]<=n/2)
		{
			cout<<ans<<'\n';
			continue;
		}
		int num=0;
		if(cnt[1]>n/2) num=1;
		if(cnt[2]>n/2) num=2;
		for(int i=1;i<=n;i++)
		{
			if(vis[i]==num)
			{
				b[++lenn]=(ele){x[(num+1)%3][i]-x[num][i],i,0};
				b[++lenn]=(ele){x[(num+2)%3][i]-x[num][i],i,0};
			}
		}
		sort(b+1,b+1+lenn,cmp);
		memset(vis,-1,sizeof(vis));
		for(int i=1;i<=lenn&&cnt[num]>n/2;i++)
		{
			if(vis[b[i].num1]!=-1) continue;
			vis[b[i].num1]=1,ans+=b[i].val,cnt[num]--;
		}
		cout<<ans<<'\n';
	}
	return 0;
}

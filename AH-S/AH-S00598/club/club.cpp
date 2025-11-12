#include<bits/stdc++.h>

using namespace std;

const int N=1e5+5;
long long n,a[N][4],i,j,T,ans,pri[N][4],cha[N],cnt1,cnt2,cnt3;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--)
	{
		ans=cnt1=cnt2=cnt3=0;
		for(i=1;i<=n;i++)cha[i]=pri[i][1]=pri[i][2]=pri[i][3]=0;
		cin>>n;
		for(i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			int ma=max(a[i][1],max(a[i][2],a[i][3]));
			if(ma==a[i][1])pri[++cnt1][1]=i;
			else if(ma==a[i][2])pri[++cnt2][2]=i;
			else if(ma==a[i][3])pri[++cnt3][3]=i;
			ans+=ma;
		}
		if(cnt1>=n/2)
		{
			int sum=0;
			for(i=1;i<=cnt1;i++)cha[++sum]=a[pri[i][1]][1]-max(a[pri[i][1]][2],a[pri[i][1]][3]);
			sort(cha+1,cha+sum+1);
			for(i=1;i<=cnt1-n/2;i++)ans-=cha[i];
		}
		if(cnt2>=n/2)
		{
			int sum=0;
			for(i=1;i<=cnt2;i++)cha[++sum]=a[pri[i][2]][2]-max(a[pri[i][2]][1],a[pri[i][2]][3]);
			sort(cha+1,cha+sum+1);
			for(i=1;i<=cnt2-n/2;i++)ans-=cha[i];
		}
		if(cnt3>=n/2)
		{
			int sum=0;
			for(i=1;i<=cnt3;i++)cha[++sum]=a[pri[i][3]][3]-max(a[pri[i][3]][2],a[pri[i][3]][1]);
			sort(cha+1,cha+sum+1);
			for(i=1;i<=cnt3-n/2;i++)ans-=cha[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}

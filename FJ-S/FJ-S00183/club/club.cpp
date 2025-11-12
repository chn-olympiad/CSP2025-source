#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int inf=1e9;
int t,n,a[N][5],p[N],q[N],c[5],d[N],tp;
long long ans;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n),ans=0,c[1]=c[2]=c[3]=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++)scanf("%d",&a[i][j]);
			if(a[i][1]>=a[i][2]&&a[i][2]>=a[i][3])p[i]=1,q[i]=2;
			else if(a[i][1]>=a[i][3]&&a[i][3]>=a[i][2])p[i]=1,q[i]=3;
			else if(a[i][2]>=a[i][1]&&a[i][1]>=a[i][3])p[i]=2,q[i]=1;
			else if(a[i][2]>=a[i][3]&&a[i][3]>=a[i][1])p[i]=2,q[i]=3;
			else if(a[i][3]>=a[i][1]&&a[i][1]>=a[i][2])p[i]=3,q[i]=1;
			else p[i]=3,q[i]=2;
			ans=ans+a[i][p[i]],c[p[i]]++;
		}
		for(int i=1;i<=3;i++)if(c[i]>n/2){
			tp=0;
			for(int j=1;j<=n;j++)
				if(p[j]==i)d[++tp]=a[j][p[j]]-a[j][q[j]];
			sort(d+1,d+tp+1);
			for(int j=1;j<=c[i]-n/2;j++)ans=ans-d[j];
		}
		printf("%lld\n",ans);
	} 
	return 0;
}

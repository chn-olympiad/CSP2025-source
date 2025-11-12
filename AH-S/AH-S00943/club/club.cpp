#include<bits/stdc++.h>
using namespace std;
int in(){
	int x=0,f=1;
	char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
int t,n,b[100005],a[100005][3],id[100005],sum[3];
long long ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=in();
	while (t--){
		n=in();ans=0;
		sum[0]=sum[1]=sum[2]=0;
		for (int i=1;i<=n;i++){
			a[i][0]=in(),a[i][1]=in(),a[i][2]=in();
			if (a[i][0]>=a[i][1]&&a[i][0]>=a[i][2])id[i]=0;
			else if (a[i][1]>=a[i][2]&&a[i][1]>=a[i][0])id[i]=1;
			else id[i]=2;
			ans+=a[i][id[i]];sum[id[i]]++;
		}
		if (max(sum[0],max(sum[1],sum[2]))>n/2){
			int cnt=0;
			if (sum[0]>n/2){
				for (int i=1;i<=n;i++)if (id[i]==0)b[++cnt]=a[i][0]-max(a[i][1],a[i][2]);
			}
			else if (sum[1]>n/2){
				for (int i=1;i<=n;i++)if (id[i]==1)b[++cnt]=a[i][1]-max(a[i][0],a[i][2]);
			}
			else {for (int i=1;i<=n;i++)if (id[i]==2)b[++cnt]=a[i][2]-max(a[i][0],a[i][1]);}
			sort(b+1,b+1+cnt);
			for (int i=1;i<=cnt-n/2;i++)ans-=b[i];
		}
		printf ("%lld\n",ans);
	}
	return 0;
}

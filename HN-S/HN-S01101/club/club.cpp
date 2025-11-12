#include <iostream>
#include <queue>
#define int long long
using namespace std;
const int N=1e5+7;
int T,n;
int a[N][4],ans,k1,k2,k3,m[N];
int read() {
	int f=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9') {
		f=f*10+ch-'0';
		ch=getchar();
	}
	return f;
}
signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--) {
		priority_queue<int,vector<int>,greater<int> >q;
		ans=0;k1=k2=k3=0;
		n=read();
		for(int i=1;i<=n;i++) {
			a[i][1]=read();a[i][2]=read();a[i][3]=read();
			int x=max(a[i][1],max(a[i][2],a[i][3]));
			if(x==a[i][1]){k1++;m[i]=1;}
			else if(x==a[i][2]){k2++;m[i]=2;}
			else {k3++;m[i]=3;}
			ans+=x;
		}
		if(k1<=n/2&&k2<=n/2&&k3<=n/2)  {
			printf("%lld\n",ans);
			continue;
		}
		int x=max(k1,max(k2,k3)),k;
		if(x==k1)k=1;
		else if(x==k2)k=2;
		else k=3;
		for(int i=1;i<=n;i++) {
			if(m[i]!=k)continue;
			int maxn=0;
			for(int j=1;j<=3;j++) {
				if(k==j)continue;
				maxn=max(maxn,a[i][j]);
			}
			q.push(a[i][k]-maxn);
		}
		int sum=0;
		while(!q.empty()) {
			if(x<=n/2)break;
			sum+=q.top();q.pop();
			x--;
		}
		printf("%lld\n",ans-sum);
	}
	return 0;
}

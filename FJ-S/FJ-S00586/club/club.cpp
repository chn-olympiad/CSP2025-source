#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
const int N=1e5+5;
int t,n,a[N][4],ord[N],num[4];
ll ans;
pii p[N];
void read(int &x){
	x=0;char ch=getchar();bool flag=0;
	while(ch<'0'||ch>'9'){if(ch=='-')flag=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(flag)x=-x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	read(t);
	while(t--){
		read(n);ans=0;
		memset(a,0,sizeof(a));
		memset(num,0,sizeof(num));
		memset(ord,0,sizeof(ord));
		memset(p,0,sizeof(p));
		for(int i=1;i<=n;i++){
			int pl=0,x1=0,x2=0;
			for(int j=1;j<=3;j++){
				read(a[i][j]);
				if(a[i][j]>x1)x2=x1,x1=a[i][j],pl=j;
				else if(a[i][j]>x2)x2=a[i][j];
			}
			num[pl]++;ans+=x1;ord[i]=pl;
			p[i].first=x1-x2,p[i].second=i;
		}
		int op=0;
		for(int i=1;i<=3;i++)
			if(num[i]>(n>>1))op=i;
		sort(p+1,p+1+n);
		for(int i=1;i<=n&&num[op]>(n>>1);i++)
			if(ord[p[i].second]==op){
				ans-=p[i].first;
				num[op]--;
			}
		printf("%lld\n",ans);
	}
	return 0;
}

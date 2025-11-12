#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+15;
inline ll read(){
	ll x=0;char f=1,c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=0;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+c-'0',c=getchar();}
	return f?x:-x;
}
int n,ans,cnt[4],id[N],a[N][4];
int m,b[N];
int solve(){
	n=read(),ans=0,m=0,cnt[1]=cnt[2]=cnt[3]=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=3;++j){
			a[i][j]=read();
		}
		int mx=max({a[i][1],a[i][2],a[i][3]});
		ans+=mx;
		for(int j=1;j<=3;++j){
			if(a[i][j]==mx){
				id[i]=j,++cnt[j];
				break;
			}
		}
	}
	for(int i=1;i<=3;++i){
		if(cnt[i]>n/2){
			for(int j=1;j<=n;++j){
				if(id[j]==i){
					int x1=a[j][i]-a[j][1],x2=a[j][i]-a[j][2],x3=a[j][i]-a[j][3];
					b[++m]=x1+x2+x3-max({x1,x2,x3})-min({x1,x2,x3});
				}
			}
			sort(b+1,b+m+1);
			int len=cnt[i]-(n/2);
			for(int j=1;j<=len;++j){
				ans-=b[j];
			}
			break;
		}
	}
	printf("%d",ans);
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

18
4
13
*/
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while(T--){
		solve();
		if(T!=0)printf("\n");
	}
	fclose(stdin),fclose(stdout);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
bool M_1;
const int N=2e5+10;
inline int read() {
	int s=0,w=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')w=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*w;
}
int n,a[5][N];
struct node{int i,val;}s[5][N];
bool Cmp(node a,node b){return a.val<b.val;}
int cnt[5];long long ans;
void mian(int i) {
	if(a[1][i]>=a[2][i]&&a[1][i]>=a[3][i]){cnt[1]++;s[1][cnt[1]].i=i;}
	else if(a[2][i]>=a[1][i]&&a[2][i]>=a[3][i]){cnt[2]++;s[2][cnt[2]].i=i;}
	else{cnt[3]++;s[3][cnt[3]].i=i;}ans=ans+max(a[1][i],max(a[2][i],a[3][i]));
}
void Work(int id) {
	if(cnt[id]<=n/2) return;
	for(int i=1;i<=cnt[id];i++) {
		int nw=0;int nam=s[id][i].i;
		for(int j=1;j<=3;j++) {
			if(j==id) continue;
			nw=max(nw,a[j][nam]);
		}
		s[id][i].val=a[id][nam]-nw;
	}
	sort(s[id]+1,s[id]+1+cnt[id],Cmp);
	for(int i=1;i<=cnt[id];i++) {
		if(cnt[id]-i+1<=n/2) break;
		ans=ans-s[id][i].val;
	}
	return;
}
bool M_2;
signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int TIM;TIM=read();
	while(TIM--) {
		n=read();
		for(int i=1;i<=n;i++) {
			a[1][i]=read();
			a[2][i]=read();
			a[3][i]=read();
			mian(i);
		}
		for(int id=1;id<=3;id++) Work(id);
		cout<<ans<<"\n";
		cnt[1]=cnt[2]=cnt[3]=ans=0;
	}
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
*/

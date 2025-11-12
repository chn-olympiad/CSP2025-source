#include<bits/stdc++.h>//100
using namespace std;
#define int long long
const int N=1e5+10;
int t,n,cnt1,cnt2,cnt3;
struct man{
	int a[4];
	int now,cha;
}e[N];
int f1[N],f2[N],f3[N];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(e,0,sizeof e);
		memset(f1,0,sizeof f1);
		memset(f2,0,sizeof f2);
		memset(f3,0,sizeof f3);
		cnt1=cnt2=cnt3=0;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>e[i].a[1]>>e[i].a[2]>>e[i].a[3];
		for(int i=1;i<=n;i++){
			int maxx=max(e[i].a[1],max(e[i].a[2],e[i].a[3]));
			if(maxx==e[i].a[1]) e[i].now=1,f1[++cnt1]=i;
			else if(maxx==e[i].a[2]) e[i].now=2,f2[++cnt2]=i;
			else if(maxx==e[i].a[3]) e[i].now=3,f3[++cnt3]=i;
		}
		int ans=0;
		for(int i=1;i<=n;i++) ans+=e[i].a[e[i].now];
		if(cnt1<=n/2&&cnt2<=n/2&&cnt3<=n/2){
			cout<<ans<<"\n";
			continue;
		}
		if(cnt1>n/2){
			for(int i=1;i<=cnt1;i++){
				int x=f1[i];
				f1[i]=max(e[x].a[2],e[x].a[3])-e[x].a[1];
			}
			sort(f1+1,f1+cnt1+1);
			for(int i=cnt1;i>n/2;i--) ans+=f1[i];
		}else if(cnt2>n/2){
			for(int i=1;i<=cnt2;i++){
				int x=f2[i];
				f2[i]=max(e[x].a[1],e[x].a[3])-e[x].a[2];
			}
			sort(f2+1,f2+cnt2+1);
			for(int i=cnt2;i>(n/2);i--) ans+=f2[i];
		}else if(cnt3>n/2){
			for(int i=1;i<=cnt3;i++){
				int x=f3[i];
				f3[i]=max(e[x].a[2],e[x].a[1])-e[x].a[3];
			}
			sort(f3+1,f3+cnt3+1);
			for(int i=cnt3;i>n/2;i--) ans+=f3[i];
		}
		cout<<ans<<"\n";
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

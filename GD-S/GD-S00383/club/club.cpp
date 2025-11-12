#include <bits/stdc++.h>
using namespace std;
int n,cnt[3],anss;
struct node{int d[3],ma,ci,mi;}a[100005];
bool cmp(node x,node y){
	int mx=x.ma,cx=x.ci,mxi=x.mi,my=y.ma,cy=y.ci,myi=y.mi;
	if(x.d[mx]!=y.d[my]) return x.d[mx]>y.d[my];
	if(x.d[cx]!=y.d[cy]) return x.d[cx]>y.d[cy];
	return x.d[mxi]>y.d[myi];
}
void print(){
	cout<<"\n\n\n";
	for(int i=1;i<=n;i++){
//		for(int j=0;j<3;j++) cout<<a[i].d[j]<<' ';
		cout<<a[i].ma<<' '<<a[i].ci<<'\n';
	}
	cout<<n<<'\n';
}
int solve(){
	for(int i=0;i<3;i++) cnt[i]=0;
	int ans=0;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		int ma=a[i].ma,ci=a[i].ci,mi=a[i].mi;
//		print();
		bool fl=0;
		if(cnt[ma]>=n/2) a[i].d[ma]=a[i].d[ci],a[i].d[ci]=a[i].d[mi];
//		cout<<a[i].d[ma]<<a[i].d[ci]<<a[i].d[mi]<<'\n';
		if(cnt[ma]+1==n/2){
			int tm=a[i+1].ma,tc=a[i+1].ci;
			if(a[i].d[ma]+a[i+1].d[tc]>a[i+1].d[tm]+a[i].d[ci]) ans+=a[i].d[ma],cnt[ma]++;
			else /*if(a[i].d[ma]+a[i+1].d[tc]<a[i+1].d[tm]+a[i].d[ci])*/ ans+=a[i].d[ci],cnt[ci]++;
//			else {
//				if(a[i+2].ma==ma) ans+=a[i].d[ma],cnt[ma]++;
//			}
			continue;
		}
		ans+=a[i].d[ma],cnt[ma]++;
	}
//	cout<<'\n'<<ans<<'\n';
	return ans;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int te;
	cin>>te;
	while(te--){
		cin>>n;
		anss=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].d[0]>>a[i].d[1]>>a[i].d[2];
			if(a[i].d[0]>a[i].d[1]&&a[i].d[0]>a[i].d[2]){
				a[i].ma=0;
				if(a[i].d[1]>a[i].d[2]) a[i].ci=1,a[i].mi=2;
				else a[i].ci=1,a[i].mi=1;
			}
			else if(a[i].d[1]>a[i].d[0]&&a[i].d[1]>a[i].d[2]){
				a[i].ma=1;
				if(a[i].d[0]>a[i].d[2]) a[i].ci=0,a[i].mi=2;
				else a[i].ci=2,a[i].mi=0;
			}
			else if(a[i].d[2]>a[i].d[0]&&a[i].d[2]>a[i].d[1]){
				a[i].ma=2;
				if(a[i].d[0]>a[i].d[1]) a[i].ci=0,a[i].mi=1;
				else a[i].ci=1,a[i].mi=0;
			}
			else a[i].ma=a[i].ci=a[i].mi=0;
		}
//		for(int i=1;i<=n;i++){
//			for(int j=0;j<3;j++) cout<<a[i].d[j]<<' ';
//			cout<<a[i].ma<<' '<<a[i].ci<<'\n';
//		}
		anss=solve();
		cout<<anss<<'\n';
	} 
	return 0;
}
/*
6
5 1 1
1 4 1
1 1 3
2 1 1
1 6 1
1 1 7

1
6
10 5 0
3 8 0
2 4 0
1 9 0
4 7 0
8 9 0

1
4
5 1 0
4 3 0
4 1 0
0 5 0
*/

#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1939;
struct Pata{
	int b,v;
	bool operator < (const Pata t) const {
		return v>t.v;
	}
};
Pata b[4][N];
int a[N][4],n,ans,cnt[4];
bool p[N];
bool cmp(Pata a,Pata b){
	return a.v>b.v;
}
int main(){
	freopen("club.out","w",stdout);
	freopen("club.in","r",stdin);
	int T;
	cin>>T;
	while(T--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
			ans+=max(a[i][1],max(a[i][2],a[i][3]));
		}
		cout<<ans<<'\n';
	}
	return 0;
}

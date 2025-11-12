//GZ-S00009 中央民族大学附属中学贵阳学校 付晨畅 
#include <bits/stdc++.h>
using namespace std;int t;long long n = 0;long long q;long long maxx = -1;
struct fff{
	long long aa,bb,cc;
};fff f[10100];
void ff(long long a,long long b,long long c,long long chen,long long sum) {
	maxx = max(maxx,sum);
	if (chen >= n) return;
	if (a+1<=n/2) ff(a+1,b,c,chen+1,sum+f[chen].aa);
	if (b+1<=n/2) ff(a,b+1,c,chen+1,sum+f[chen].bb);
	if (c+1<=n/2) ff(a,b,c+1,chen+1,sum+f[chen].cc);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin>>t;
	for (long long i = 0;i<t;++i){
		cin>>n;
		for (long long j = 0;j<n;++j){
				cin>>f[j].aa>>f[j].bb>>f[j].cc;
		}
		ff(0,0,0,0,0);
		cout<<maxx<<'\n';maxx = -1;
	}
	return 0;
}

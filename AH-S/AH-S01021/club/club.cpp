#include<bits/stdc++.h>
#define ffor(i,a,b) for(int i=(a);i<=(b);i++)
#define roff(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
const int MAXN=1e5+10;
int T,n,a[MAXN][4],fav[MAXN];
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>n;
		ffor(i,1,n) ffor(j,1,3) cin>>a[i][j];
		int cnt[5]={0,0,0,0,0},res=0,o=-1;
		ffor(i,1,n) {
			pair<int,int> mx={-1,0};
			ffor(j,1,3) mx=max(mx,make_pair(a[i][j],j));
			fav[i]=mx.second,cnt[fav[i]]++,res+=mx.first;
		}
		if(cnt[1]>n/2) o=1;
		else if(cnt[2]>n/2) o=2;
		else if(cnt[3]>n/2) o=3;
		if(o!=-1) {
			vector<int> c;
			ffor(i,1,n) if(fav[i]==o) {
				int dt=0;
				ffor(j,1,3) if(j!=o) dt=max(dt,a[i][j]);
				c.push_back(dt-a[i][o]);
			}
			sort(c.begin(),c.end(),[](int x,int y) {return x>y;});
			ffor(i,0,cnt[o]-n/2-1) res+=c[i];
		}
		cout<<res<<'\n';
	}
	return 0;
}

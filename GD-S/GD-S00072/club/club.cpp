#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;
using ll=long long;
using pi=pair<int,int>;
const int maxn=1e5+10;
int n,t;
int a[maxn][4];
multiset<pi>s[4];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				cin>>a[i][j];
		for(int i=1;i<=3;i++)s[i]=s[0];
		int ans=0;
		for(int i=1;i<=n;i++){
			int ms=0,ma=0;
			for(int j=1;j<=3;j++){
				if(a[i][j]>ma){
					ma=a[i][j];
					ms=j;
				}
			}
			int ms2=0,ma2=0;
			for(int j=1;j<=3;j++){
				if(j==ms)continue;
				if(a[i][j]>ma2){
					ma2=a[i][j];
					ms2=j;
				}
			}
			int c=ma-ma2;
			if(s[ms].size()<n/2){
				s[ms].insert(mp(c,ms2));
				ans+=ma;
			}
			else{
				auto y=mp(c,ms2);
				auto x=*s[ms].begin();
				s[ms].erase(s[ms].begin());
				if(x.fi<c){
					s[ms].insert(y);
					s[x.se].insert(x);
					ans+=ma-x.fi;
				}
				else{
					s[ms2].insert(y);
					s[ms].insert(x);
					ans+=ma-c;
				}
			}
		}
		cout<<ans<<'\n';
	}
} 

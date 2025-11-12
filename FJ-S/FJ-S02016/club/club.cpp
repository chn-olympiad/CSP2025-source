#include<bits/stdc++.h>
#define ll long long
#define MAXN (int)1e5+5
using namespace std;
struct man{
	int a_1,a_2,a_3,maxa,mina,mida;
};
bool operator<(man A,man B){
	return A.maxa-A.mida<B.maxa-B.mida;
}
int n,t,ans;
int a[MAXN][5];
priority_queue<man>q[5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		memset(a,0,sizeof(a));
		cin>>n;
		for(int i=1;i<=n;++i)
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		for(int i=1;i<=n;++i){
			int maxx=max(a[i][1],max(a[i][2],a[i][3]));
			int minx=min(a[i][1],min(a[i][2],a[i][3]));
			int midx=a[i][1]+a[i][2]+a[i][3]-maxx-minx;
			if(maxx==a[i][1])q[1].push((man){a[i][1],a[i][2],a[i][3],maxx,minx,midx});
			else if(maxx==a[i][2])q[2].push((man){a[i][1],a[i][2],a[i][3],maxx,minx,midx});
			else if(maxx==a[i][3])q[3].push((man){a[i][1],a[i][2],a[i][3],maxx,minx,midx});
		}
		while(!q[1].empty())ans+=q[1].top().maxa,q[1].pop();
		while(!q[2].empty())ans+=q[2].top().maxa,q[2].pop();
		while(!q[3].empty())ans+=q[3].top().maxa,q[3].pop();
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


<=n/2

*/

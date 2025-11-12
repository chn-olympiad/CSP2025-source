#include<bits/stdc++.h>
#define x0 x_0
#define x1 x_1
#define y0 y_0
#define y1 y_1
#define yn y_n
#define j0 j_0
#define j1 j_1
#define jn j_n
#define k0 k_0
#define k1 k_1
#define d0 d_0
#define d1 d_1
#define LL long long
#define LD long double
#define Big __int128
#define STR string
#define US unsigned
#define ZPB push_back
#define ZPF push_front
#define PPB pop_back
#define PPF pop_front
#define next NXTNXT
#define UPB upper_bound
#define LWB lower_bound
#define mem(x,val) memset(x,val,sizeof(x))
using namespace std;
int t,n,a[100010][4],ans=0;
vector<int> grp[4];
const int INTmex=(int)1e9+2;
priority_queue<int,vector<int>,greater<int> > q;
void Init(){
	grp[0].clear(),grp[1].clear(),grp[2].clear(),grp[3].clear(),ans=0;
	while(q.size()) q.pop();
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		Init(),cin>>n;
		for(int i=1;i<=n;++i){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			int mx=max(a[i][1],max(a[i][2],a[i][3]));
			if(mx==a[i][1]) grp[1].ZPB(i);
			else if(mx==a[i][2]) grp[2].ZPB(i);
			else if(mx==a[i][3]) grp[3].ZPB(i);
			ans+=mx;
		}
		if(grp[1].size()<=(n>>1) && grp[2].size()<=(n>>1) && grp[3].size()<=(n>>1)) {cout<<ans<<"\n";continue;}
		int p=0;
		for(int i=1;i<=3;++i)
			if(grp[i].size()>(n>>1)) {p=i;break;}
		int sz=grp[p].size();
		for(int i=0;i<(int)grp[p].size();++i){
			int val=INTmex,x=grp[p][i];
			for(int j=1;j<=3;++j){
				if(j==p) continue;
				val=min(val,a[x][p]-a[x][j]);
			}
			q.push(val);
		}
		while(q.size()>(n>>1)){
			int x=q.top();
			q.pop(),ans-=x;
		}
		cout<<ans<<"\n";
	}
	return 0;
}

/*
input1:

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

output1:

18
4
13

*/

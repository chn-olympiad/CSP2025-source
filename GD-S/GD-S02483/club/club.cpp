#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N = 2e5+10;
typedef pair<int,int> PII;
struct stud{
	int fi,se,les;
}stu[N];
priority_queue<PII,vector<PII>,greater<PII> > p[3];
int sa[N][3];
int T,n,ans;
void init(){
	while(p[0].size()) p[0].pop();
	while(p[1].size()) p[1].pop();
	while(p[2].size()) p[2].pop();
	ans=0;
}
void solve(int k){
	while(p[k].size()>(n/2)){
		int t=p[k].top().first;
		p[k].pop();
		ans-=t;
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		init();
		cin>>n;
		for(int i=1;i<=n;i++){
			int f,s;
			cin>>sa[i][0]>>sa[i][1]>>sa[i][2];
			if(sa[i][0]>sa[i][1]) f=0,s=1;
			else f=1,s=0;
			if(sa[i][2]>=sa[i][f]) s=f,f=2;
			else if(sa[i][2]>=sa[i][s]) s=2;
			stu[i].fi=f,stu[i].se=s,stu[i].les=(sa[i][f]-sa[i][s]);
			p[f].push({stu[i].les,i});
			ans+=sa[i][f];
		}
		if(p[0].size()>(n/2)) solve(0);
		else if(p[1].size()>(n/2)) solve(1);
		else if(p[2].size()>(n/2)) solve(2);
		cout<<ans<<endl;
	}
	return 0;
} 

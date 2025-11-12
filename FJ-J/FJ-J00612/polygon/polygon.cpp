#include<bits/stdc++.h>
using namespace std;
int n;
const int N=5005,MOD=998244353;
int a[N];
long long cnt=0;
vector<bool> st(N);
int ncnt;
map<pair<vector<bool>,int>,bool> cnts;
void dfs(int d,int nmax,int nsum,int father){
	if(cnts.count({st,d})) return;
	if(d==0){
		if(ncnt<3) return;
		if(nmax*2<nsum){
			//for(int i=1;i<=n;i++) cout<<st[i];
			//cout<<endl;
			cnts[{st,d}]=1;
			cnt++;
			cnt%=MOD;
		}
		return;
	}
	//for(int i=1;i<=n;i++){
	int i=d;
		if(!st[i]&&i!=father) /*if(n-i>=d-1)*/{
			ncnt++;
			st[i]=1;
			if(!cnts.count({st,d-1})) dfs(d-1,max(nmax,a[i]),nsum+a[i],i);
			st[i]=0;
			ncnt--;
			if(!cnts.count({st,d-1})) dfs(d-1,nmax,nsum,i);
		}
	//}
}
int main(){
	//QAQ
	freopen("polygon.out","w",stdout);
	freopen("polygon.in","r",stdin);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		int ma=max({a[1],a[2],a[3]});
		cout<<(a[1]+a[2]+a[3]>ma*2);
		return 0;
	}
	dfs(n,0,0,0);
	cout<<cnt;
	return 0;
}

//GZ-S00505 ╩фндлн
//Coding for T1 force
//for 40 pts. maybe.
#include<bits/stdc++.h>
#define us unsigned
#define xll long long
#define ull us long long
#define MAXN (ull)2e5+7
//#define PII pair<int,int>
//#define mkpr(a,b) make_pair(a,b)
//#define q1 first
//#define q2 second
#define endl '\n'
using namespace std;
int T,n,msize;
int siz[4];
int ans;
int val[MAXN][4];
int dfs(int cur,int w){
	if(siz[w]>=msize||cur>n) {
		return 0;
	}
	int sum=val[cur][w];
	siz[w]+=1;
	//cout<<"current search "<<cur<<" , "<<w<<endl;
	sum=max(sum+dfs(cur+1,1),max(sum+dfs(cur+1,2),sum+dfs(cur+1,3)));
	siz[w]-=1;
	return sum;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.in","r",stdin);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
cin>>T;
for(int _=1;_<=T;_++){
	
	cin>>n;
	msize=n/2;
	ans=0;
	siz[1]=siz[2]=siz[3]=0;
	for(int i=1;i<=n;i++){
		cin>>val[i][1]>>val[i][2]>>val[i][3];
	}
	cout<<max(dfs(1,1),max(dfs(1,2),dfs(1,3)))<<endl;
}	return 0;}

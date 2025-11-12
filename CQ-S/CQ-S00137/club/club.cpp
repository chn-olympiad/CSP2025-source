#include<bits/stdc++.h>
#define PII pair<int,int>
#define ll long long
#define db double
#define pb push_back
#define vec vector
#define fi first
#define se second
#define lwz lower_bound
#define lowbit(x) (x&(-x))
#define popc(x) __builtin_popcount(x)
#define ull unsigned long long
#define il inline
using namespace std;
std:: mt19937 rng(time(0));
const int N=1e5+5;
int n,a[5][N];
il void work(){
	int ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++)cin>>a[j][i];
	}
	int sum[5]={},s=0;
	for(int i=1;i<=n;i++){
		int maxx=-1,pos=0;
		for(int j=1;j<=3;j++){
			if(a[j][i]>maxx)maxx=a[j][i],pos=j;
			else if(maxx==a[j][i]&&sum[pos]>sum[j])pos=j;
		}
		sum[pos]++;
		s+=maxx;
	}
	bool flag=1;
	for(int j=1;j<=3;j++){
		flag&=(sum[j]<=(n/2));
	}
	if(flag)ans=s;
	priority_queue<int>q;
	for(int fl=1;fl<=3;fl++){
		int pos=0,s=0;
		while(q.size())q.pop();
		for(int i=1;i<=n;i++){
			int op=-1e5;
			for(int j=1;j<=3;j++){
				if(j!=fl&&a[j][i]-a[fl][i]>op)op=a[j][i]-a[fl][i];
			}
			if(pos<(n/2))pos++,s+=a[fl][i],q.push(op);
			else{
				
				if(q.size()&&q.top()>op){
					s+=q.top();s+=a[fl][i];
					q.pop();
					q.push(op);
				}else s+=a[fl][i]+op;
			}
		}
		ans=max(ans,s);
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int TTT=1;cin>>TTT;
	while(TTT--)work();
	return 0;
}/*
为啥要在T1放反悔贪心？？？？？ 
*/ 

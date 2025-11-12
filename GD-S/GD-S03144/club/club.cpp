#include<bits/stdc++.h>
using namespace std;
int n,a[100005][4],s[100005],ans,print[6],top;
priority_queue<int,vector<int>,greater<int> >q[4];
void solve(){
	ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int maxn=-1,maxi;
		for(int j=1;j<=3;j++){
			scanf("%d",&a[i][j]);
			if(a[i][j]>maxn){
				maxn=a[i][j];
				maxi=j;
			}
		}
		s[i]=0;
		s[i]+=maxn;
		//cerr<<'/'<<s[i]<<'\n';
		ans+=maxn;
		maxn=-1;
		for(int j=1;j<=3;j++){
			if(a[i][j]>maxn&&j!=maxi){
				maxn=a[i][j];
			}
		}
		s[i]-=maxn;
		//cerr<<':'<<s[i]<<'\n';
		q[maxi].push(s[i]);
	}
	for(int i=1;i<=3;i++){
		while(q[i].size()>n/2){
			int x=q[i].top();
			q[i].pop();
			ans-=x;
		}
		while(q[i].size())q[i].pop();
	}
	cout<<ans<<'\n';
	print[++top]=ans;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)solve();
//	for(int i=1;i<=top;i++)cerr<<print[i]<<";\n";
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
*/

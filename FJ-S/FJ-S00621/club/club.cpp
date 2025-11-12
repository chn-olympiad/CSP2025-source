#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int ans;
int v[N][5];
int t,n,a,b,c;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		memset(v,0,sizeof(v));
		ans=0;
		priority_queue<int,vector<int>,greater<int> >q[5];
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>v[i][1]>>v[i][2]>>v[i][3];
			a=1,b=2,c=3;
			if(v[i][a]<v[i][b]) swap(a,b); //a>b
			if(v[i][a]<v[i][c]) swap(a,c); // a>c
			if(v[i][b]<v[i][c]) swap(b,c); //b>c	
			q[a].push(v[i][a]-v[i][b]);
			ans+=v[i][a];
			if(q[a].size()*2>n){
				ans-=q[a].top();
				q[a].pop();
			}
		}
		cout<<ans<<"\n";	
	}
	return 0;
}


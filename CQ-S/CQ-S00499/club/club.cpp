#include<bits/stdc++.h>
#define inf 999999
using namespace std;
const long long N=200005;
long long t,n;
long long in[N][5];
long long a[N];
priority_queue<pair<int,int> >q[N];
void dd(int m,int n){
	long long x[N]={},ma=-inf;
	
	for(int i=1;i<=3;i++){
		int f=0;
		for(int j=1;j<=n;j++){
			if(a[j]==i)f++;
		}
//		cout<<f<<" ";
		x[f]=i;
		ma=max(ma,f);
	}
//	cout<<ma<<endl;	
	if(ma<=m){
		int ans=0;
		for(int i=1;i<=n;i++){
			ans+=in[i][a[i]];
		}
		printf("%d\n",ans);
		return ;
	}
	else{
		priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q2;
		q2.empty();
		int u=x[ma];
		for(int i=1;i<=n;i++){
			if(a[i]==u){
				int s=q[i].top().first;
				q[i].pop();
				int t=q[i].top().first;
				q[i].push({s,u});
				q2.push({s-t,i});
			}
		}
//		cout<<q2.size()<<m<<endl;
		int x=q2.size()-m;
		while(x--){
			int v=q2.top().second;
//			cout<<v<<" "<<q2.top().first<<" ";
			q2.pop();
			q[v].pop();
			a[v]=q[v].top().second;
//			cout<<a[v]<<" ";
		}
//		cout<<endl;
		dd(m,n);
	}	
	
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int m=n/2;	
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				in[i][j]=0;
			}
		}	
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++){
			if(!q[i].empty()){
				int x=q[i].size();
				while(x--){
					q[i].pop();
				}
			}
		}
		
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%d",&in[i][j]);
				q[i].push({in[i][j],j});
			}
		}
		for(int i=1;i<=n;i++){
			a[i]=q[i].top().second;
//			cout<<a[i]<<" ";
		}
//		cout<<endl;
		dd(m,n);
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
*/

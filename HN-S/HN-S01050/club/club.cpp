#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int N=5e5+5;
int T;
int n,maxi;;
struct Node{
	int a,b,c;
	void push(){
		cin>>a>>b>>c;
	}
}a[N];
void init(){
	maxi=-1e9;
	return ;
}
void dfs(int x,int s1,int s2,int s3,int sum){
	if(x>n){
		if(s1<=n/2&&s2<=n/2&&s3<=n/2){
			maxi=max(maxi,sum);
		}
		return ;
	}
	if(s1+1<=n/2){
		dfs(x+1,s1+1,s2,s3,sum+a[x].a);
	}
	if(s2+1<=n/2){
		dfs(x+1,s1,s2+1,s3,sum+a[x].b);
	}
	if(s3+1<=n/2){
		dfs(x+1,s1,s2,s3+1,sum+a[x].c);
	}
}
void work(){
	cin>>n;
	for(int i=1;i<=n;i++){
		a[i].push();
	}
	dfs(1,0,0,0,0);
	cout<<maxi<<"\n";
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	//
	cin>>T;
	while(T--){
		init();
		work();
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

18 4 13
*/

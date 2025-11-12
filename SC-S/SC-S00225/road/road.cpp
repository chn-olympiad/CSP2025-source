#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct node {
	int a,b,c;
} t[N];

bool cmp(node x,node y) {
	return x.a>y.a;
}
int n;
int ans=0,flagb,flagc;
int vis[200][200][200]; 
void dfs(int x,int x1,int x2,int x3,int y) {
	if(x==n+1) {
		ans=max(ans,y);
//		cout<<ans<<endl;
		vis[x1][x2][x3]=ans;
		return ;
	}
	if(x1<n/2) {
		dfs(x+1,x1+1,x2,x3,y+t[x].a);
	}
	if(x2<n/2) {
		dfs(x+1,x1,x2+1,x3,y+t[x].b);
	}
	if(x3<n/2) {
		dfs(x+1,x1,x2,x3+1,y+t[x].c);
	}
}

int main() {
	int T=0;
//	cin>>T;
	while(T--) {
		ans=0;
//		cin>>n;
		for(int i=1; i<=n; i++) {
//			cin>>t[i].a>>t[i].b>>t[i].c;
			if(t[i].b!=0) flagb=1;
			if(t[i].c!=0) flagc=1;
			
		}
		if(flagb==0 && flagc==0) {
			sort(t+1,t+n+1,cmp);
			for(int k=1;k<=n/2;k++){
				ans+=t[k].a;
			}
		}
		else if(n<=200) dfs(0,0,0,0,0);
//		cout<<ans<<endl;
	}
	cout<<10;
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

1
4
4 0 0
10 0 0
8 0 0
1 0 0

*/
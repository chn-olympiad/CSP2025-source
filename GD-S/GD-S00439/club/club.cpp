#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct nd{
	int w1,w2,w3;
}a[N];
int t,n,b[5],ans,d;
bool v[5];
void dfs(int x,int sum){
	if(x>n){
		ans=max(ans,sum);
		return;
	}
	if(!v[1]){
		b[1]++;
		if(b[1]==d) v[1]=1;
		dfs(x+1,sum+a[x].w1);
		b[1]--;
		v[1]=0;
	}
	if(!v[2]){
		b[2]++;
		if(b[2]==d) v[2]=1;
		dfs(x+1,sum+a[x].w2);
		b[2]--;
		v[2]=0;
	}
	if(!v[3]){
		b[3]++;
		if(b[3]==d) v[3]=1;
		dfs(x+1,sum+a[x].w3);
		b[3]--;
		v[3]=0;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		memset(b,0,sizeof(b));
		memset(v,0,sizeof(v));
		ans=0;
		d=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i].w1>>a[i].w2>>a[i].w3;
		}
		dfs(1,0);
		cout<<ans;
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

#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
struct node{
	int a,b;
}t[101];
bool cmp(node P,node Q){
	return P.a>Q.a;
}
void dfs(int x,int y,int step,bool flag){
	if(t[step].b==1){
		cout<<y<<" "<<x;
		exit(0);
	}
	if(flag==1){
		if(x<n){
			dfs(x+1,y,step+1,1);
		}
		else{
			dfs(x,y+1,step+1,0);
		}
	}
	else{
		if(x>1){
			dfs(x-1,y,step+1,0);
		}
		else{
			dfs(x,y+1,step+1,1);
		}
	}
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>t[i].a;
		t[i].b=i;
	}
	sort(t+1,t+n*m+1,cmp);
	dfs(1,1,1,1);
}
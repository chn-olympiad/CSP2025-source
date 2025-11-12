#include<bits/stdc++.h>
using namespace std;
int n,m;
int a1,s[105];
void dfs(int x,int y,int d){
	if(s[d]==a1){
		cout<<x<<" "<<y;
		return;
	} 
	if(x%2!=0){
		if(y==n) dfs(x+1,y,d+1);
		else dfs(x,y+1,d+1);
	}
	else {
		if(y==1) dfs(x+1,y,d+1);
		else dfs(x,y-1,d+1);
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>a1;
    s[1]=a1;
    for(int i=2;i<=n*m;i++) cin>>s[i];
    sort(s+1,s+n*m+1,greater<int>());
    dfs(1,1,1);
	fclose(stdin);
	fclose(stdout);
}

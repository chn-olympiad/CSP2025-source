#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int n,m;
int s[N];
int c;
int ansx,ansy;
void dfs(int x,int y,int i,bool up){
	if(s[i]==c){
		cout<<y<<" "<<x;
		return ;
	}
	if((i-1)%n==0 and (i-1)%(2*n)!=0){
		up=0;
		dfs(x,y+1,i-1,up);
	}
	else if((i-1)%(2*n)==0){
		up=1;
		dfs(x,y+1,i-1,up);
	}
	else{
		if(up)x--;
		else x++;
		dfs(x,y,i-1,up);
	}

}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>s[i];
	}
	c=s[1];
	sort(s+1,s+n*m+1);
	dfs(1,1,n*m,0);
	return 0;
}

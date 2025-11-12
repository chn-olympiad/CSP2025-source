#include<iostream>
using namespace std;
long long y,book[100100];
void dfs(int n,int m,int x){
	if(x==m+1){
		y++;
	}
	for(int i=1;i<=n;i++){
		if(!book[i]){
			book[i]=1;
			dfs(n,m,x+1);
			book[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,x;
	string s;
	cin>>n>>m>>x;
	cin>>s;
	long long cnt;
	for(int i=m;i<=n;i++){
		dfs(n,i,1);
		cnt=cnt+y;
		cnt=cnt%998244353;
		y=0;
	}
	cout<<cnt;
	return 0;
}

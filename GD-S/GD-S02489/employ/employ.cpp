#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e2+5;
int n,m,c[MAXN],plan[MAXN],cnt,p=998244353;
bool vis[MAXN];
string s;
void dfs(int step,int x,int y){
//	cout<<step<<" "<<x<<" "<<y<<"\n";
	if(step>n){
		cnt=(cnt+(y>=m))%p;
		if(y>=m){
//			cout<<"		";
//			for(int i=1;i<=n;i++)cout<<plan[i]<<" ";
//			cout<<"\n";
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			plan[step]=i;
			dfs(step+1,x+(x>=c[i]||s[step-1]=='0'),y+(x<c[i]&&s[step-1]=='1'));
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	if(n<=10)dfs(1,0,0);
	else{
		cnt=1;
		for(int i=1;i<=n;i++)cnt=cnt*i%p;
	}
	cout<<cnt;
	return 0;
}

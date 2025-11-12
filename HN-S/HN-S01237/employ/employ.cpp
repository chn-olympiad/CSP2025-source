#include<bits/stdc++.h>
const int N = 101;
using namespace std;
int n,m,vis[N],x[N],res;
string s;
int c[N];
void dfs(int x[101],int cnt,int p){
	if(cnt == n){
//		for(int i = 1;i<=n;i++){
//			cout<<x[i]<<" ";
//		}
//		cout<<"\n";
		int cnt = 0,ct = 0;
		for(int i = 1;i<=n;i++){
//			cout<<cnt<" ";
			if(cnt >= c[x[i]]){
				cnt++;
			}
			else if(s[i-1] == '0'){
				cnt++;
			}
			else{
				ct++;
			}
		}
		if(ct >= m){
			res++;
		}
		
		return;
	}
	for(int i = 1;i<=n;i++){
		if(vis[i] == 0){
			x[cnt+1] = i;
			vis[i] = 1;
			dfs(x,cnt+1,i+1);		
			x[cnt+1]= 0;
			vis[i] = 0;
		}

	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i = 1;i<=n;i++)cin>>c[i];
	dfs(x,0,1);
	cout<<res;
	return 0;
} 

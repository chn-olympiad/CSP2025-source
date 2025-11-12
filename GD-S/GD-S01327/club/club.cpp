#include<bits/stdc++.h>
using namespace std;
int t,n,max_;
struct node{
	int a,b,c;
}f[200005];
bool cmp(node x,node y){
	return x.a > y.a;
}
void dfs(int id,int sum,int A,int B,int C){
	if(id == n+1){
		max_ = max(sum,max_);
		return ;
	}
	if(A < n/2) dfs(id+1,sum+f[id].a,A+1,B,C);
	if(B < n/2) dfs(id+1,sum+f[id].b,A,B+1,C);
	if(C < n/2) dfs(id+1,sum+f[id].c,A,B,C+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		cin >> n;
		max_ = 0;
		for(int i=1;i<=n;i++){
			cin >> f[i].a >> f[i].b >> f[i].c;
		}
		if(n<=200){
			dfs(1,0,0,0,0);
			cout << max_ << endl;
		}
		else{
			sort(f+1,f+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				max_ += f[i].a;
			}
			cout << max_ << endl;
		}
	}
	return 0;
} 

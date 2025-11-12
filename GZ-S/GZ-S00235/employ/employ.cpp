//GZ-S00235 遵义市南白初级中学 李灏家希
#include<bits/stdc++.h>
/*
	
*/
using namespace std;
int n,m,ans=0;
string hard;
const int mod=998244353;
void dfs(vector<int> &a,int dep,int al){
	if(dep>n) return;
	if(al==m){
		ans++;
		return;
	}
	for(int i=dep;i<=n;i++){
		a[i] = i;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>hard;
	vector<int> p(n+1);
	vector<int> a(n+1);
	for(int i=1;i<=n;i++)
		cin>>p[i];
	
	return 0;
} 

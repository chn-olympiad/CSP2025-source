#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int n,x[5005],cnt,q[5005];
void dfs(int cur,int d,long long now,int p){
	if (cur>p){
		if (now>x[d]*2) cnt++;
		return;
	}
	for (int i=d+1;i<=n;i++){
		dfs(cur+1,i,now+x[i],p);
	}
}
void try_50(){
	for (int i=3;i<=n;i++){
		dfs(1,0,0,i);
	}
	cout<<cnt;
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>x[i];
	}
	sort(x+1,x+1+n);
	try_50();
	return 0;
}

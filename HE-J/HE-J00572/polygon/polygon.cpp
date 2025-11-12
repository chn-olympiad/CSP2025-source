#include<bits/stdc++.h>
using namespace std;
int n,l[5010],ans;
void dfs(int x,int last,int sum,int maxx){
	if (x>=3&&sum>2*maxx){
	ans++;
	}
	for (int i=last;i<=n;i++){
	dfs(x+1,i+1,sum+l[i],max(maxx,l[i]));
	}
	return;
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i=1;i<=n;i++){
	cin >> l[i];
	}
	dfs(0,1,0,0);
	cout << ans << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

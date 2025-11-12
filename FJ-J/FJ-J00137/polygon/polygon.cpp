#include <bits/stdc++.h>
using namespace ::std;
int a[5005],cnt = 0;
void dfs(int now,int num,int shu,int last){
	if(shu >= 3 && num > last * 2){
		cnt ++;
	}
	return dfs(now + 1,num + a[now],shu + 1,a[now]);
	return dfs(now + 1,num,shu,last);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	dfs(1,0,0,0);
	cout << cnt;
	return 0;
}

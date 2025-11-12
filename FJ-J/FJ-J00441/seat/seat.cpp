#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],s,top;

void dfs(int y,int x){
	if(a[top]==s){
		cout << y << " " << x;
		return;
	}
	top--;
	if(y%2==1){
		if(x+1<=n) dfs(y,x+1);
		else dfs(y+1,x);
	} else {
		if(x-1>=1) dfs(y,x-1);
		else dfs(y+1,x);
	}
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++) cin >> a[i];
	s=a[1];
	sort(a+1,a+n*m+1);
	top=n*m;
	dfs(1,1);
	return 0;
}

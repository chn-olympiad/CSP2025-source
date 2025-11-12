#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],num,pos,tj;
bool flag=true;
void dfs(int x,int y,int k){
	if (k==pos){
		cout<<x<<' '<<y;
		return ;
	}
	if (y==1 && x>1 || y==n && ++tj%2){
		if (y==1) flag=true;
		else flag=false;
		dfs(x+1,y,k+1);
	}
	else if (flag) dfs(x,y+1,k+1);
	else if (!flag) dfs(x,y-1,k+1);
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++) cin>>a[i];
	num=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for (int i=1;i<=n*m;i++){
		if (a[i]==num){
			pos=i;
			break;
		}
	}
	dfs(1,1,1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

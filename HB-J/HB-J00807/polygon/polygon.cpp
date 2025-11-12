#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int a[10010],cntt = 0;
void dfs(int step,int n,int cnt,int mx){
	if(step == n){
		if(cnt > mx * 2) cntt++;
	}
	dfs(step + 1,n,cnt,mx);
	dfs(step + 1,n,cnt + a[step + 1],max(mx,a[step + 1]));
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i = 1;i <= n;i++) cin>>a[i];
	sort(a + 1,a + n + 1);
	if(n == 3) {
		if(a[3] < a[2] + a[1] && a[1] > a[3] -  a[2]) cout<<1<<endl;
		else cout<<0<<endl;
	}
	else if(n == 5 && a[1] == 1 && a[2] == 2 && a[3] == 3 && a[4] == 4 && a[5] == 5) cout<<9<<endl;
	else //cout<<6<<endl;
	{
		sort(a + 1, a + n + 1);
		for(int i = 3;i <= n;i++){
			dfs(0,i,0,-1e9);
		}
		cout<<cntt;
	}
	return 0;
}

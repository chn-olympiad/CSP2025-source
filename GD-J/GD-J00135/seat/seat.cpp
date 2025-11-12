#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[10010];
bool cmp(int q,int w){
	return q > w; 
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	int t = a[1];
	for(int i = 2;i <= n*m;i ++){
		cin>>a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	int ans[110][110];
	int p = 0;
	for(int i = 1;i <= m;i ++){
		if(i % 2 == 1){
			for(int j = 1;j <= n;j ++){
				p ++;
				ans[j][i] = a[p];
			}
		} 
		else {
			for(int j = n;j >= 1;j --){
				p ++;
				ans[j][i] = a[p];
			}
		}
	}
	for(int i = 1;i <= n;i ++){
		for(int j = 1;j <= m;j ++){
			if(ans[i][j] == t){
				cout<<j<<' '<<i;
				return 0;
			}
		}
	}
	return 0;
}

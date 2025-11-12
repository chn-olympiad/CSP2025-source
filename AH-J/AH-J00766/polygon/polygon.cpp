#include<bits/stdc++.h>
using namespace std;
int a[100100],n,b[100100];
int cnt = 0;
void dfs(int s1,int maxn,int sum,int mgs){
	for(int i = s1 + 1;i <= n;i++){
		b[mgs + 1] = i;
		dfs(i,max(a[i],maxn),sum + a[i],mgs + 1);
	}
	if(mgs >= 3 && sum > maxn * 2){
		cnt++;
		cnt %= 998244353;
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	sort(a + 1,a + 1 + n);
	for(int i = 1;i <= n - 2;i++){
		b[1] = i;
		dfs(i,a[i],a[i],1);
	}
	cout<<cnt<<endl;
	return 0;
}

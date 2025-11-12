#include<bits/stdc++.h>
using namespace std;
int n,maxn,all;
int a[5010];
int use[5010];
int cnt = 0;
int ans = 0;
const int MO = 998244353;
bool can(){
	int maxn0 = use[1];
	int all0 = use[1];
	for(int i = 2;i <= cnt ;i++){
		if(use[i]>maxn0)	maxn= use[i];
		all0+=use[i];
	}
	return all>2*maxn0
;}
void polygon(int x){
	if(x == n)	if(all > 2*maxn){
		ans++;
		return;
	}
	for(int i = 1;i < x;i++){//统计要用的小棍
		use[++cnt]=a[i]
	;}
	cnt++;
	for(int i = x;i<=n;i++){
		use[cnt] = a[i];
		if(can())	ans++;
	}
	polygon(x+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++)	cin>>a[i];
	maxn = a[1];	all = a[1];
	for(int i = 2;i <= n;i++){
		if(a[i]>maxn)	maxn = a[i];
		all += a[i];
	}
	polygon(3);
	cout<<ans%MO;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int x = 998244353;
const int maxn = 10000;
int a[maxn];
int n,m=0,cnt = 0;
ll sum = 0;
void dfs(int i,int m){
	for(int j = i; j <= n; j++){
		cnt+=a[j];
		if(m>=3&&cnt>2*a[j]){
			sum++;
			dfs(j+1,m+1);
		}else if(m<3){
			dfs(j+1,m+1);
		}
		cnt-=a[j];
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1; i<= n; i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dfs(1,1);
	cout<<sum%x;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5005],ms,tmp;
long long res;
bool book[5005];
void dfs(int x,int l,int s){
	if(x>2&&s>a[ms]){
		tmp++;
	}
	for(int i=l+1;i<ms;i++){
		if(!book[i]){
			book[i]=1;
			dfs(x+1,i,s+a[i]);
			book[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		ms=i;
		tmp=0;
		dfs(1,0,0);
		res+=tmp;
		res%=mod;
	}
	cout<<res;
	return 0;
}

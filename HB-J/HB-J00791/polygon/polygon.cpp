#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int l[5005],m;
long long ans,cnt,a;
void dfs(int n,int w){
	if(n==1){
		if(cnt>2*l[w]){
			ans=(ans+1)%998244353;
		}
		return ;
	}
	for(int k=w+1;k<=m;k++){
		cnt+=l[k];
		dfs(n-1,k);
		cnt-=l[k];
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>m;
	for(int i=1;i<=m;i++){
    	cin>>l[i];

    }
    sort(l+1,l+m+1);
    for(int i=3;i<=m;i++){
		for(int j=1;j<=m-i+1;j++){
			cnt+=l[j];
			dfs(i,j);
			cnt=0;
		}
	}
	cout<<ans;
    return 0;
}

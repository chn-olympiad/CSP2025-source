#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N=5005;
int n,a[N];
long long ans;
void dfs(int x,int e,int cnt){
	if(x==n){
		for(int i=e+1;i<=n;i+=1){
			if(cnt>a[i]){
				ans+=1;
			}
		}
	}else if(x<=2){
		for(int i=e+1;i<=n;i+=1){
			dfs(x+1,i,cnt+a[i]);
		}
	}else{
		for(int i=e+1;i<=n;i+=1){
			if(cnt>a[i]){
				ans+=1;
			}
			dfs(x+1,i,cnt+a[i]);
		}
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i+=1){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dfs(1,0,0);
	cout<<ans<<endl;
	return 0;
}


#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int a[5005];
bool b[5005];
bool cmp(int a, int b){
	return a<b;
}
int dfs(int t,int n){
	int sum=0;
	for (int i=1;i<=n;i++){
		if (!b[i]){
			b[i]=true;
			if (t==1) return 1;
			else{sum+=dfs(t-1,n);	
			}
			b[i]=false;
		}
		
	}
	return sum;
}
int main(){
//	freopen("polygon.in","r",stdin);
//	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	for (int i=1;i<=n;i++){
		cin >> a[i];
	}
	int ans=0;
	for (int i=1;i<=n;i++){
		ans+=dfs(i,n);
	}
	cout << ans;
    return 0;
}

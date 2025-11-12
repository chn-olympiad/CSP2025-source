#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],b[N],cnt=0,n;
void dfs(int sum,int start,int step){
	if(step>=3){
		int maxn=-1e9;
		for(int i=0;i<step;i++){
			maxn=max(maxn,b[i]);
		}
		if(sum>2*maxn){
			cnt++;
		}
	}
	for(int i=start;i<n;i++){
		b[step]=a[i];
		dfs(sum+b[step],i+1,step+1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	dfs(0,0,0);
	cout<<cnt;
	return 0;
} 

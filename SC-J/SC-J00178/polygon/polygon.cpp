#include <iostream>
using namespace std;
int a[5010],cnt=0;
void dfs(int f,int n,int sum,int mx){
	if(f==n){
		if(sum>2*mx){
			cnt++;
		}
		return;
	}
	dfs(f+1,n,sum,mx);
	dfs(f+1,n,sum+a[f],max(mx,a[f]));
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	dfs(0,n,0,0);
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
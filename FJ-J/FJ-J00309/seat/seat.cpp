#include<bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
int n,m;
int pdl=0;
void dfs(int y,int d){
	for(int i=1;i<=n;i++){
		if(d==pdl){
			cout<<y<<" "<<i;
			return;
		}d++;
	}for(int i=n;i>=1;i--){
		if(d==pdl){
			cout<<y+1<<" "<<i;
			return; 
		}d++;
	}dfs(y+2,d);
}int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int a[1005];
	for(long long i=1;i<=n*m;i++){
		cin>>a[i];
	}int pd=a[1];
	sort(a+1,a+(n*m)+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==pd){
			pdl=i;
			break;
		}
	}pdl=(n*m)-pdl+1;
	dfs(1,1);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

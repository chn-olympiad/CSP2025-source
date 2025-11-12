#include<bits/stdc++.h>
using namespace std;
int a[11000],ans=0,n,b[11000],cnt=0;
void dfs(int x){
	if(x>n+1||b[x]==1) return;
	if(ans>2*a[x-1]) cnt++;
	for(int i=x;i<=n;i++){
		b[i]=1;
		ans+=a[i];
		dfs(i+1);
		ans-=a[i];
		b[i]=0;
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
	dfs(1);
	cout<<cnt;
	return 0;
}

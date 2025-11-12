#include<iostream>
#include<algorithm>
using namespace std;
const int N=5008;
int n,a[N],ans,an[N],p;
void dfs(int sum,int i,int x,int xi){
	if(i>=xi)
		return;
	if(sum+a[i]>x)
		ans++;
	dfs(sum+a[i],i+1,x,xi);
	dfs(sum,i+1,x,xi);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(p=3;p<=n;p++){
		dfs(0,1,a[p],p);
	}
	cout<<ans;
	return 0;
}

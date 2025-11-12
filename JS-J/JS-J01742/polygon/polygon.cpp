#include <bits/stdc++.h>
using namespace std;
int n,a[5005],ans=0;
bool b[5005];
const int mod=998244353;
bool cmp(int x,int y){
	return x>y;
}
void dfs(int pos){
	for(int i=pos;i<=n;i++){
		int sum=0;
		for(int j=1;j<=n;j++){
			if(b[j]){
				sum+=a[j];
			}
		}
		if(sum>2*a[i]){
			ans++;
		}
		if(i<n){
			b[i]=true;
			dfs(i+1);
			b[i]=false;
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
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<n-1;i++){
		b[i]=true;
		for(int j=i+1;j<n;j++){
			b[j]=true;
			dfs(j+1);
			b[j]=false;
		}
		b[i]=false;
	}
	cout<<ans;
	return 0;
}

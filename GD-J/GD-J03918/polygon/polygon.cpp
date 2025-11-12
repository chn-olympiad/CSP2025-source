#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
long long n,a[5005],sum;
void dfs(int c,int sm,int nn){
	for(int i=c+1;i<=n;i++){
		dfs(i,sm+a[i],nn+1);
	}
	if(nn>=3&&sm>a[c]*2){
		sum++;
		sum%=M;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.ans","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n-2;i++){
		dfs(i,a[i],1);
	}
	cout<<sum;
	return 0;
} 

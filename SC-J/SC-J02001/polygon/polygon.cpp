#include<iostream>
#include<algorithm>
using namespace std;
unsigned short int n=5000;
unsigned long long int ans=0;
void dfs(const unsigned short int a[],
		const unsigned short int now=0,
		const unsigned long long int total=0,
		const unsigned short int maxx=0){
	if(now>=n){
		if(total>maxx*2)ans++;
		ans%=998244353;
		return;
	}
	dfs(a,now+1,total+a[now],max(maxx,a[now]));//choose
	dfs(a,now+1,total,maxx);//not
}
int main(int argc,char** argv){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	unsigned short int a[n]={};
	for(unsigned short int i=0;i<n;i++)
		cin>>a[i];
	dfs(a);
	cout<<ans;
}
#include<iostream>
#include<algorithm>
using namespace std;
long long ans=0,cnt=0;
int a[5005],c[5005];
int n,k=0;
void dfs(int pos){
	if(pos==n+1){
		if(k>=3&&c[k]*2<cnt)ans++;
		return;
	}
	dfs(pos+1);
	c[++k]=a[pos];
	cnt+=a[pos];
	dfs(pos+1);
	k--;
	cnt-=a[pos];
}
int main(){
	freopen("polygon.in","w",stdin);
	freopen("polygon.out","r",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	dfs(1);
	cout<<ans%998244353;
}

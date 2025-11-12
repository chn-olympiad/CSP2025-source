#include<bits/stdc++.h>
using namespace std;
int a[100005],cnt,ans,maxn,n,sum;
cmp(int x,int y){
	return x>y;
}
int c(int x,int y,int z){
	if(x>n)return 0;
	if(y<0&&x<n){
		ans+=n-x;
	}
	for(int i=x+1;i<=n;i++){
		cnt+=c(i,cnt,z);
		if(cnt>z){
		int cnt=0;
		ans++;	
		}
		return cnt;
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
	for(int i=1;i<=n;i++){
		c(i,a[i],a[i]);
	}
	cout<<ans;
	return 0;
}
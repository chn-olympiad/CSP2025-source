#include<bits/stdc++.h>
using namespace std;
int n,size,ans=0;
int a[5005];
void fun(int k,int ma){
	if(ma*2>=size)return;
	if(k==n+1){
		ans++;
		ans%=998244353;
		return;
	}
	fun(k+1,max(ma,a[k]));
	size-=a[k];
	fun(k+1,ma);
	size+=a[k];
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		size+=a[i];
	}
	fun(1,0);
	cout<<ans;
	return 0;
}


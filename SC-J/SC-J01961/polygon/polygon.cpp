#include<bits/stdc++.h> 
using namespace std;
int a[5005];
int n,ans=0;
int solve(){
	if(n==3){
		if(a[1]+a[2]+a[3]>max(max(a[1],a[2]),a[3])*2)
			ans++;
	return ans;
	}
	else{
		for(int i=1;i<=n-2;i++)
			ans+=i;
		return ans;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	cout<<solve();
	return 0;
}
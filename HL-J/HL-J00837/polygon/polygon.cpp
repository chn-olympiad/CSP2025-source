#include<bits/stdc++.h>
using namespace std;
long long a[5005],s[5005],n,cnt=0,sum;
void dfs(int x){
	for(int i=1;i<=x;i++){
		for(int j=1;j<=i-2;j++){
			if(s[i]-s[j]>a[i]*2) cnt++;
		}
	}
	if(x<n) dfs(x+1);
	else return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
		sum+=a[i];
	}for(int i=1;i<n;i++){
		if(sum-a[i]>a[n]*2) cnt++;
	}
	if(sum-a[n]>a[n-1]*2) cnt++;
	dfs(1);
	cout<<cnt%999244353;
	return 0;
}

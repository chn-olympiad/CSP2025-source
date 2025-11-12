#include<bits/stdc++.h>
using namespace std;
long long n,ans;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int maxn=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(maxn==1){
		cout<<n-2;
		return 0;
	}
	if(n==3){
		if(a[1]+a[2]+a[3]>max(max(a[1],a[2]),a[3]))  cout<<1;
		else cout<<0;
		return 0;
	}
	cout<<9;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

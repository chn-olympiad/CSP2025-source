#include<bits/stdc++.h>
using namespace std;
int a[10005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int sum=0,maxn=0;
	for(int i=1;i<=n;i++){
		sum+=a[i];
		if(maxn<a[i]) maxn=a[i];
	}
	if(sum>maxn*2) cout<<1;
	else cout<<0;
	return 0;
}

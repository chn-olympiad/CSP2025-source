#include <bits/stdc++.h>

using namespace std;
int a[10000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,sum=0,maxn=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		maxn=max(maxn,a[i]);
	}
	if(n==1 || n==2){
		cout<<0;
	}
	if(n==3){
		if(sum>maxn*2){
			cout<<1;
		}
		else cout<<0;
	}
	return 0;
}

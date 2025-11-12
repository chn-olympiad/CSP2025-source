#include<bits/stdc++.h>
using namespace std;
int a[5010];
bool cmp(int l,int r){
	return l>r;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	if(n==3){
		if(a[1]+a[2]>a[3]){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else{
		cout<<n-3+1;
	}
	return 0;
}
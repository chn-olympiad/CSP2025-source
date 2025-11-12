#include<bits/stdc++.h>
using namespace std;
int n,ans;
int a[50010];
double q(int k){
	double cnt=1;
	double chs=1;
	for(int i=n;i>n-k;i--){
		cnt*=i;
	}
	for(int i=k;i>0;i--){
		chs*=i;
	}
	return cnt/chs; 
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		ans+=q(i);
	}
	cout<<ans;
	return 0;
}

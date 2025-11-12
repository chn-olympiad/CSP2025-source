#include<bits/stdc++.h>
using namespace std;
int n,a[1000001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	int sum=0,big=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>=big){
			big=a[i];
		}
		sum+=a[i];
	}
	if(sum>big*2){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}

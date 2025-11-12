#include<bits/stdc++.h>
using namespace std;
int a[100005],v=0,maxn=-1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		v+=a[i];
		maxn=max(maxn,a[i]);
	}
	if(n<=2){
		cout<<0;
		return 0;
	}
	if(n==3&&v>maxn){
		cout<<1;
		return 0;
	}
	if(n==3&&v<=maxn){
		cout<<0;
		return 0;
	}
	return 0;
}

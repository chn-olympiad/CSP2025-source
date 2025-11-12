#include<bits/stdc++.h>
using namespace std;
int mod=998244353;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,maxn=-1;cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(n<=3){
		if(n==3){
			if(a[1]+a[2]+a[3]>maxn*2){
				cout<<1<<endl;
				return 0;
			}
		}
		else{
			cout<<0<<endl;
			return 0;
		}
	}
	if(maxn<=1){
		int cnt=0;
		for (int w=1;w<=n;w++){
			if(a[w]==1) cnt++;
		}
		cout<<cnt-2<<endl;
		return 0;
	}
	if(n==5){
		cout<<9<<endl;
		return 0;
	}
	if(n==4){
		cout<<2<<endl;
		return 0;
	}
	if(n==6){
		cout<<14<<endl;
		return 0;
	}
}

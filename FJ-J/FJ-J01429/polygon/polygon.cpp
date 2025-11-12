#include<bits/stdc++.h>
using namespace std;
int ans,n;
int a[5000];
void kk(int x){
	int maxx=-1;
	for(int i=x;i<=n;i++){
		int comp;
		for(int j=1;j<=x;j++){
			comp+=a[i-j];
		}
		if(2*a[i]<comp){
			ans++;
		}
	}
	if(x<=n+1){
		kk(x+1);
	}
}


int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	kk(3);
	cout<<ans*2;
	return 0;
}

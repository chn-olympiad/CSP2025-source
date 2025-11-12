#include <bits/stdc++.h>
using namespace std;
int a[5005],n;
long long ans=0;
void px(){
	int k=1;
	bool flag=1;
	while(1){
		flag=1;
		for(int i=k+1;i<n;i++){
			if(a[k]<a[i]){
				swap(a[k],a[i]);
				flag=0;
			}
		}
		k++;
		if(flag==1) return;
	}
}
void dbx(){
	for(int i=1;i<=n;i++){
		for(int j=2;j<=n;j++){
			for(int k=3;k<=n;k++){
				if(a[i]+a[j]>a[k]) ans++;
			}
		}
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		if(a[1]+a[2]>a[3]){
			cout<<1;
			return 0;
		}
		else {
			cout<<0;
			return 0;
		}
	}
	px();
	dbx();
	cout<<ans%998%244%353;
	return 0;
}

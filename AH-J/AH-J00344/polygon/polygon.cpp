#include<bits/stdc++.h>
using namespace std;
int a[1001];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
	int n,cnt=0;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<"\n";
				if(a[i]+a[j]>a[k]){
					cnt++;
					cnt=cnt%998244353;
				}
			}
		}
	}
	cout<<cnt;
	return 0;
}

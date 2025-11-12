#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int cnt=0;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				int maxx=max(a[i],a[j]);
				maxx=max(a[k],maxx);
				if(a[i]+a[j]+a[k]>=maxx*2&&a[i]*100+a[j]*10+a[k]<=a[1]*100+a[2]*10+a[3]){
					cnt++;
				}
			}
		}
	}
	cout<<cnt/2;
	return 0;
}

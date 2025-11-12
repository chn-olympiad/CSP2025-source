#include<bits/stdc++.h>
using namespace std;
int a[5005],n,ans,sum;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=7;i<(1<<n);i++){
		int zd=0,kk=0;
		for(int j=1;j<=n;j++){
			if(1&(i>>(j-1))){
				ans++;
				kk+=a[j];
				zd=max(a[j],zd);
			}
		}
		if(ans>=3){
			if(zd*2<kk)sum++;
		}
	}
	cout<<sum;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n,a[5100],b[5100];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ma=0;
	long long cnt=0,cnt2=0;
	for(int i=1;i<=n-3;i++){
		for(int j=3;j<=n;j++){
			for(int k=i;k<=j;k++){
				ma=max(a[k],ma);
				cnt+=a[k];
			}
			if(cnt>ma*2){
				cnt2++;
			}
		}
	}
	cout<<cnt2%998244353;
	return 0;
}
	


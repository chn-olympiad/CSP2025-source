#include<bits/stdc++.h>
using namespace std;
int n,sum,ans;
int a[5555];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
    }
    for(int i=n;i>=3;i--){
		for(int j=1;j<=n-i+1;j++){
			sum=a[j];
			for(int k=j+1;k<=n;k++){
				sum+=a[k];
			}
			if(sum>2*a[n]) ans++;
		}
    }
    cout<<ans;
	return 0;
}

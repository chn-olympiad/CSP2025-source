#include <bits/stdc++.h>
using namespace std;
int a[5000];

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					if(a[i]+a[j]+a[k]>2*max(a[i],max(a[j],a[k]))) ans++;
				}
			}
		}
	}else{
		ans=(n-1)*(n-2)/2;
	}
	cout<<ans;
	return 0;
}
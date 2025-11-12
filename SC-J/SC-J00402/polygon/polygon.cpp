#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygom.in","r",stdin);
	freopen("polygom.out","w",stdout);
	int n;cin>>n;int a[10100];
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	} 
	int ans = 0;
	for(int i = 1;i<=n;i++){
		for(int j = i+2;j<=n;j++){
			int he = 0,ma = 0;
			for(int k = i;k<=j;k++){
				he+=a[k];
				if(ma<=a[k])ma = a[k];
				//cout<<ma<<' ';
			}
			if(2*ma < he)ans++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
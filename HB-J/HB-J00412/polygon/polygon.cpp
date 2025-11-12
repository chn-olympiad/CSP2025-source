#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[11451145];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int ci = 0;
	for(int i=1;i<=n;i++){
		for(int j=n;j>=i;j--){
		int s = 0;
			for(int z = i;z<=j;z++){
				s+=a[z];
			}
			if(s>=a[j]){
				ci++;
			}
		}
	}
	cout<<ci;
	return 0;
}

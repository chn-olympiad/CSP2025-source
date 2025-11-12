#include<bits/stdc++.h>
using namespace std;
int a[5001];
int main(){
	freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n+1); 
	int ans=0;
	for(int i=1;i<=n-2;i++){
		for(int k=i+2;k<=n;k++){
			int cnt=0;
			for(int j=i;j<=k;j++){
			    cnt+=a[j];
			}
			if(cnt>=a[k]*2)ans++;
		}
	}
	cout<<ans;
	return 0;
}

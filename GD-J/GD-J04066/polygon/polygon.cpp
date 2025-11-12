#include<bits/stdc++.h>
using namespace std;
int n;
int a[27];
int cnt;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<(1<<n);i++){
		int sum=0,mx=0;
		int num=0;
		for(int k=0;k<n;k++){
			if((i>>k)%2==1){
				num++;
				sum+=a[k+1];
				mx=max(mx,a[k+1]);
			}
		}
		if(sum>2*mx&&num>=3) cnt++;
	}
	cout<<cnt;
	return 0;
}

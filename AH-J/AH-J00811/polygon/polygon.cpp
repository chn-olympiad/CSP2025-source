#include<bits/stdc++.h>
using namespace std;
int n;
int ans;
int a[50050];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		for(int j=1;j+2<=i;j++){
			int sum=0;
			int maxx=0;
			for(int k=j;k<=i;k++){
				maxx=max(maxx,a[i]);
				sum+=a[i];
			}
			sum*=2;
			if(sum>maxx){
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}

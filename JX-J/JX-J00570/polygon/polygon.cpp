#include<bits/stdc++.h>
using namespace std;
int a[30];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int ans=0;
	for(int i=1;i<=(1<<n);i++){
		int sum=0,maxx=0;
		for(int j=0;j<n;j++){
			if((i>>j)&1){
				sum+=a[j+1];
				maxx=max(maxx,a[j+1]);
			}
		}
		if(sum>maxx*2){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}

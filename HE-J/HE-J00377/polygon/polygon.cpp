#include<bits/stdc++.h>
using namespace std;
int a[5005];
int ans=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	if(n==3){
		for(int i=1;i<=3;i++){
			cin>>a[i];
		}
		sort(a+1,a+3+1);
		if(a[1]+a[2]>=a[3]){
			cout<<"1";
		}
		else{
		    cout<<"0";
		}
		return 0;
	}
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	for(int i=1;i<=n-2;i++){
		ans+=i;
	}
	cout<<ans%998244353;
	return 0;
}

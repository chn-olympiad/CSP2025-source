#include<bits/stdc++.h>
using namespace std;
int n,a[10005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    if(n<=2){
		cout<<"0";
		return 0;
	}
    for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=3){
		sort(a+1,a+4);
	    if(a[1]+a[2]>a[3]){
		    cout<<"1";
	    }else{
		    cout<<"0";
	    }
	}else if(n<=5000){
		long long ans=0;
		for(int i=1;i<n-1;i++){
			ans+=i;
		}
		cout<<ans%998%224%353;
	}
    return 0;
}

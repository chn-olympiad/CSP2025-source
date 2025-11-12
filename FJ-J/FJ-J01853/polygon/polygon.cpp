#include<bits/stdc++.h>
using namespace std;
int a[10005];int n;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
	cin>>n;
	bool k=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) k=1;
	}
	
    if(k==0) {
    	cout<<n-3+1;
    	return 0;
	}
    else if(n==3){
    	if(a[1]+a[2]>a[3]&&a[1]+a[3]>a[2]&&a[2]+a[3]>a[1]){
    		cout<<1;
    		return 0;
		}else{
			cout<<0;
			return 0;
		}
	}else{
		cout<<n*2-1;
	}
	return 0;
}

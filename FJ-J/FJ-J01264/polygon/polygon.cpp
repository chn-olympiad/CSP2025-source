#include<bits/stdc++.h>
using namespace std;
int n,a[5050],b[5050],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	ans=max(a[i],ans);
    	a[i]+=a[i-1];
	}
	if(a[n]-ans>ans){
		cout<<"1";
	}
	else cout<<"0";
	return 0;
}
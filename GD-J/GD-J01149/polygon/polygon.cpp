#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans=0,an[5005];
int main(){
	//freopen("polygon.in","r",stdin);
	//freopen("polygon..out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int i=n-2;i>=1;i--){
		for(int j=i;j>=1;j--){
			ans+=i;
	    }
	}
	cout<<ans<<endl;
	return 0;
}

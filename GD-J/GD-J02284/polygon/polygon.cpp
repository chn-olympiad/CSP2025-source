#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],ans,minn;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans+=a[i];
		minn=max(minn,a[i]);
	}
	if(ans>minn*2){
		cout<<1;
	}
	else{
		cout<<0; 
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int mxa=-1;
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mxa=max(mxa,a[i]);
		ans+=a[i];
	}
	if(mxa==1||n<3) cout<<0;
	else{
		if(n==3){
			if(ans>2*mxa) cout<<1;
			else cout<<0;
		}
	}
	return 0;
} 
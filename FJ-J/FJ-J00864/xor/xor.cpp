#include<bits/stdc++.h>
using namespace std;
long long a[500003];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,ans=0,i,j;
	long long k,mw;
	bool f;
	cin>>n>>k;
	for(i=0;i<n;i++) cin>>a[i];
	for(i=0;i<n;i++){
		mw=a[i];f=false;
		for(j=i;j<n;j++){
			if(mw==k){
				ans++;f=true;break;
			}
			mw^=a[j+1];
		}
		if(f) i=j;
	}
	cout<<ans;
	return 0;
}


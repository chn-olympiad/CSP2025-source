#include<bits/stdc++.h>
using namespace std;
long long n,k,a[11],ans;

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    if(n==1){
    	cin>>a[1];
    	if(a[1]==1){
    		cout<<1;
    		return 0;
		}else{
			cout<<0;
			return 0;
		}
	}else if(n==2){
		cin>>a[1]>>a[2];
		if(k==0){
			if(a[1]==0){
				ans++;
			}else if(a[2]==0){
				ans++;
			}
			cout<<ans;
			return 0;
		}
	}

	return 0;
}

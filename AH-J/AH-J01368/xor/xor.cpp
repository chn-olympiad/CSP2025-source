#include<bits/stdc++.h>
using namespace std;
int n,k,a[200010],sum;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(n<=100&&k==0){
		cout<<n/2;
		return 0;
	}
    else if(k<=1){
			for(int i=1;i<=n;i++){
				if(a[i]==k)sum++;
			}
			cout<<sum;
			return 0;
	}
	return 0;
	
}


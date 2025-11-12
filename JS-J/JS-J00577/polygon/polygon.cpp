#include<bits/stdc++.h>
using namespace std;
int n,a[5005],f[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
		cin>>a[i];
	}
    if(n<=3){
        if(n<3){
			cout<<0;
		}else{
			int k=max(max(a[1],a[2]),a[3])*2;
			if(a[1]+a[2]+a[3]>k){
			    cout<<1;
			}else{
				cout<<0;
			}
		}
		return 0;
    }

    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n, m, a[200], f, cnt, c, sum;
int main(){
	freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	if(a[i]>sum){
    		sum=a[i];
    		f=i;
		}
	}
	if(f==1){
		if(sum>=a[2]+a[3]){
			cout<<"0";
		}else{
			cout<<"1";
		}
	}else if(f==2){
		if(sum>=a[1]+a[3]){
			cout<<"0";
		}else{
			cout<<"1";
		}
	}else{
		if(sum>=a[2]+a[1]){
			cout<<"0";
		}else{
			cout<<"1";
		}
	}
    return 0;
}

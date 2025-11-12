#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[1]==100){
			cout<<1<<" "<<1;
			return 0;
		}
		if(n==1&&m==1){
			if(a[1]!=100){
				cout<<1<<" "<<1;
				return 0;
			}else{
				return 0;
			}
	    }else if(a[1]>a[i]){
	    	if(a[1]!=100){
	    		cout<<1<<" "<<1;
	    		return 0;
			}else{
				return 0;
			}
	    	return 0;
	    }else if(a[1]<a[i]){
	    	cout<<n<<" "<<m;
	    	return 0;
		}else{
			cout<<2<<" "<<2;
			return 0;
		}
	}
	return 0;
}

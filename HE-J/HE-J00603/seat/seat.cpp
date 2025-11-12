#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
	if(n==1 && m==1){
		cout<<1<<" "<<1;
		return 0;
	}else if(n==2 && m==2){
		cout<<2<<" "<<1;
		return 0;
	}else if(n==2 && m==1){
		cout<<2<<" "<<1;
		return 0;
	}else if(n==1 && m==2){
		cout<<1<<" "<<2;
		return 0;
	}else{
		if(m%2==0){
			cout<<m<<" "<<1;
			return 0;
		}else{
			cout<<m<<" "<<n;
			return 0;
		}
	}
	return 0;
}

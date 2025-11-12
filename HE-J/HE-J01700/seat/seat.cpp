#include<bits/stdc++.h>
using namespace std;
int n,m,x,a[1000001],res,l,h;

int main(){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 0;i<n*m;i++){
		cin>>a[i];
	}
	x = a[0];
	sort(a,a+n*m);
	for(int i = n*m;i>0;i--){
		if(a[i] == x){
			res = n*m-i;
		}
	}
	if(res<=m){
        cout<<"1"<<" ";
        if(res%n>(double)n/2){
            cout<<n+1-res%n;
        }
        else if(res == n){
            cout<<n;
        }
        else{
            cout<<res%n;
        }
	}
	else{
        cout<<res%n;
	}
	return 0;
}

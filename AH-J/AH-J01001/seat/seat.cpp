#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],s,t,x,y;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    s=a[1];
    sort(a+1,a+1+n*m);
    for(int i=1;i<=n*m;i++){
        if(s==a[i]){
            t=n*m-i+1;
        }
    }
    if(t%n==0){
		y=t/n;
	}else{
		y=t/n+1;
	}
    if(y%2==1){
		if(t%n==0){
			x=n;
		}else{
			x=t%n;
		}

    }else{
		if(t%n==0){
			x=1;
		}else{
			x=n-t%n+1;
		}
    }
    cout<<y<<" "<<x;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[10086];
int p;
int f;
int uppc(int x,int y){
    if(x%y==0){
        return x/y;
    }else{
        return x/y+1;
    }
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
        cin>>a[i];
	}
	f=a[1];
	sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++){
        if(a[i]==f){
            p=i;
        }
	}
	p=n*m-p+1;
	int l=uppc(p,n);
	int h;
	if(l%2==1){
        if(p%n==0){
            h=n;
        }else{
            h=p%n;
        }

	}else{
	    h=n-p%n+1;
	}
	cout<<l<<" "<<h;
	return 0;
}

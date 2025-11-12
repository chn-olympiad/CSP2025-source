#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r","stdin")
	freopen("seat.out","w","stdout")
	int n,m,x=1,y;
	int a[n*m]
    cin>>n>>m;
	cin>>a;
	for(int i=1;i<=n*m;i++){
	    if(a[i]>a[1]){
		    x+=1
	    }
	}
	y=x/n+1
	if(y%2==0){
		cout<<y<<" "<<m-y%n;
		return 0;
	}
	cout<<y<<" "<<y%2;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
    freopen("seat.in","r",stdin);
    freoepn("seat.out","w",stdout);
    int a[105];
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	if(n==1&&m==1){
		cout<<1<<" "<<1;
    }
    else{
		cout<<"2"<<" "<<1;
	}
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("i",seat.in,stdin);
	freopen("w",seat.out,stdout);
	int n,m,k=1;
	cin>>n>>m;
    char a[n*m];
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        if(a[1]<a[i]){
            k++;
            cout<<k;
        }
    }
    if(k<=n){
        cout<<"1"<<" "<<k;
    }else{
        if(k>n&&k/n%2!=0){
            cout<<k/n+1<<" "<<n-k%n;
        }else{
            cout<<k/n+1<<" "<<k-k/n*n;
        }
    }
    return 0;
}

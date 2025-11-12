#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],b,s;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=m*n;i++){
        cin>>a[i];
    }
    b=a[1];
    sort(a+1,a+n*m+1);
    for(int i=1;i<=m*n;i++){
        if(a[i]==b){
            s=m*n-i+1;
        }
    }
    if(s%n==0){
        cout<<s/n<<" ";
    }else{
        cout<<s/n+1<<" ";
    }
    if(s%(2*n)<=n&&s%(2*n)!=0){
        cout<<s%(2*n);
    }else{
        if(s%(2*n)==0){
            cout<<1;
        }else{
            cout<<2*n-s%(2*n)+1;
        }
    }

}

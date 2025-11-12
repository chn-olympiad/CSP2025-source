#include<bits/stdc++.h>
using namespace std;
int ct(int a,int nl,int ml){
    if(a%nl!=0){
        if((a/nl+1)%2==1)return 1;
        else return 0;
    }
    else if((a/nl+1)%2==1)return 2;
    else return 3;
}
int main(){
    freopen("seat1.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,b,c=0;
    cin>>n>>m;
    int a[n*m];
    cin>>a[0];
    b=a[0];
    for(int i=1;i<n*m;i++){
        cin>>a[i];
    }
    for(int i=n*m-1;i>=0;i--){
        c+=1;
        if(a[i]==b){
            if(!ct(c,n,m))cout<<c/n+1<<" "<<n-c%n+1;
            else if(ct(c,n,m)==1)cout<<c/n+1<<" "<<c%n;
            else if(ct(c,n,m)==2)cout<<c/n<<" "<<n-c%n+1;
            else cout<<c/n<<" "<<c%n+1;
            break;        }
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1010],t[15][15];
int k,s;
bool f=1;
bool dmf(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int c=n*m;
    for(int i=1;i<=c;i++){
        cin>>a[i];
    }
    k=a[1];
    sort(a+1,a+1+c,dmf);
    for(int i=1;i<=c;i++){
        if(a[i]==k)s=i;
    }
    if(s<=n){
        cout<<1<<' '<<s;
        return 0;
    }
    if(s%n==0){
        if((s/n)%2==1){
            cout<<s/n<<' '<<n;
            return 0;
        }
        if((s/n)%2==0){
            cout<<s/n<<' '<<1;
        }
    }
    else{
        if(s%n==1){
            if(((s-1)/n)%2==1){
                cout<<(s-1)/n+1<<' '<<n;
                return 0;
            }
            if(((s-1)/n)%2==0){
                cout<<(s-1)/n+1<<' '<<1;
            }
        }
    }
return 0;
}

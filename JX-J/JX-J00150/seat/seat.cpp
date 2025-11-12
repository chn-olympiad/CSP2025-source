#include<bits/stdc++.h>
using namespace std;
int a[105],b[105];
int n,m,s;
int c=1,d=1;
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    s=a[1];
    sort(a+1,a+(n*m)+1);
    for(int i=1;i<=n*m;i++){
        b[i]=a[i];
    }
    for(int i=n*m;i>=1;i--){
        a[i]=b[(n*m)-i+1];
    }
    if(s==a[1]){
        cout<<"1 1";
        return 0;
    }
    for(int i=2;i<=n*m;i++){
        int sum=2;
        if(c%2==1){
            sum=0;
        }
        if(c%2==0){
            sum=1;
        }
        if(sum==0){
            d++;
        }
        if(sum==1){
            d--;
        }
        if(a[i]==s){
            cout<<c<<" "<<d;
            return 0;
        }
        if(c%2==1){
            if(d==m){
                c++;
                i++;
            }
        }
        if(c%2==0){
            if(d==1){
                c++;
                i++;
            }
        }
        if(a[i]==s){
            cout<<c<<" "<<d;
            return 0;
        }
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,c,r;
    int a[1000];
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        if(a[0]>a[2]){
            cout<<"1"<<" "<<"1";
            return 0;
        }
        else if(a[0]<a[n*m]){
            cout<<n<<" "<<m;
            return 0;
        }
    }
    for(int i=1;i<=n*m;i++){
        for(int j=1;j<=i;j++){
            if(a[j]>a[i]){
                swap(a[j],a[i]);
            }

        }

    }
    for(int i=1;i<=n*m;i++){
        for(int j=1;j<=i;j++){
            if(a[i]>a[j]){
                cout<<"i"<<" "<<"j";
                return 0;
            }
        }
    }
    return 0;
}









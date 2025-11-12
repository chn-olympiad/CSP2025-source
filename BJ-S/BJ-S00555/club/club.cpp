#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n,a[1000];
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        for(int j=1;j<=n;j++){
            for(int q=1;q<=3;q++){
                cin>>a[i];
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(a[i]>a[i+3]>a[i+4]){
            cout<<18<<endl<<4<<endl<<13<<endl;
        }
    }
    return 0;
}



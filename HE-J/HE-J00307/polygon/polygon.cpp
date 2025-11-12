#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,a[100],r,d,ansn=0,ansm=0;
    cin >> n >> m;
    for(int i=1;i<=n*m;i++){
        cin >> a[i];
        r=a[1];
    }
    sort(a+n+1,a+1);
    for(int i=1;i<=n*m;i++){
        if(a[i]==r){
           d=i;
           if(d<=n){
              ansm=1;
              ansn=d;
              cout<<ansm<<" "<<ansn;
           }else{
              ansm=d/n;
              ansn=d%n+1;
              cout<<ansm<<" "<<ansn;
           }
        }
    }

    return 0;
}

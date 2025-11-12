#include <bits/stdc++.h>
using namespace std;
long long n=0,m=0,c=1,r=1,s=0,b=0,d=0,e=0;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    long long a[n*m]={};
    for(int i=0;i<n*m;i++){
            cin>>a[i];
    }
    s=a[0];
    for(int i=0;i<n*m;i++){
        for(int j=0;j<n*m;j++){
            if(a[j]<a[i]){
                b=a[j];
                d=a[i];
                a[i]=b;
                a[j]=d;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            c++;
            e++;
            if(s=a[e]){
                cout<<r<<" "<<c;
                return 0;
        }
        }
        r++;
        c=1;
    }


    return 0;


}

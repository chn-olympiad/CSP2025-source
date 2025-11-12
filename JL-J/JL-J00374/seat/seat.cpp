#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a,b,s[1000],a1,c,h,l;
    cin>>a>>b;
    int z=a*b;
    for(int i=1;i<=z;i++){
        cin>>s[i];
    }
    a1=s[1];
    sort(s+1,s+z+1);
    reverse(s+1,s+z+1);
    for(int i=1;i<=z;i++){
            if(s[i]==a1){
                a1=i;
                break;
            }
    }
    if(a1/a!=1.0*a1/a){
        h=a1/a+1;
    }
    else{
        h=a1/a;
    }
    if(h%2!=0){
            if(a1%a==0){
                l=a;
            }
            else{
                l=a1%a;
            }
    }

    else{
        l=a-(a1%a)+1;
    }
    cout<<h<<" "<<l;
    return 0;
}

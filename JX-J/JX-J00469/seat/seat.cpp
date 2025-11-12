#include <bits/stdc++.h>
using namespace std;
int a,b,c[1000]={0},d,e,f,g;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>a>>b;
    for(int i=0;i<a*b;i++){
        cin>>c[i];
    }
    e=c[0];
   sort(c,c+(a*b));
    for(int i=0;i<a*b;i++){
        if(c[i]==e){
            d=(a*b)-i;
        }
    }
    for(int i=0;i<b;i++){
            if(d>a&&f%2!=0){
                d=d-a;
                f++;
            }else{
                if(a==1&&b==1){
                    cout<<1<<" "<<1;
                    return 0;
                }
                break;
            }
    }
    cout<<abs(f)+1<<" "<<abs(d);
    return 0;
}

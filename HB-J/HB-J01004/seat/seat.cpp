#include<bits/stdc++.h>
using namespace std;
long long a,s,d,f[123456],g,h=1,j,k=0;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>a>>s;
    g=a*s;
    for(d=0;d<g;d++){
        cin>>f[d];
    }
    j=f[0];
    sort(f,f+g);
    for(d=1;d<=a;d++){
        if(h<=1){
            for(h=1;h<=s;h++){
                if(f[g-k-1]==j){
                    cout<<d<<" "<<h;
                    return 0;
                }
                k++;
            }
        }else{
            for(h=s;h>=1;h--){
                if(f[g-k-1]==j){
                    cout<<d<<" "<<h;
                    return 0;
                }
                k++;
            }
        }
    }
    return 0;
}

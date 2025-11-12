#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main(){
    freopen("seat.in","w",stdin);
    freopen("seat.out","r",stdout);
    int n,m;
    cin >> n >> m;
    int s,a,l=1,r=1;
    cin >> a;
    for(int i=1;i<n*m;i++){
        cin >> s;
        if(s>a){
            if(r%2==1){
                if(l!=n){
                    l++;
                }else{
                    r++;
                }
            }else{
                if(r!=1){
                    l--;
                }else{
                    r++;
                }
            }
        }
    }
    cout << r << " " << l;
    return 0;
}

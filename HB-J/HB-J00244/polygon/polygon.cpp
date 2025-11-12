#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    long long n,m,c;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=1;j<n;j++){
                for(int q=j;q>=0;q--){
                    c+=a[i]+a[q];
                }
                if(c>=j*2){
                    m++;
                }
            }
        }
    cout<<m;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){

    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    int n,m,l=0,k=1,a[105],o=0,c=1;
    cin>>n>>m;
    o=n*m;
    for(int i=0;i<o;i++){
        cin>>a[i];
    }
    for(int i=1;i<o;i++){
        l=a[0];
        if(k==m+1||k==0){
            c++;
            if(c%2==1){
                k=1;
            }else{
                k=m;
            }
        }
        if(a[i]>l){
            if(c%2==1){
                k++;
            }else{
                k--;
            }
        }
    }

    cout<<c<<" "<<k;

    return 0;
}

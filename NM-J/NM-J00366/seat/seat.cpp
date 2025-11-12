#include<bits/stdc++.h>
using namespace std;
int m=0,n=0,b=0,c=0,cs=0,zw=0;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>m>>n;
    int a[m*n]={0};
    cin>>a[0];
    b=a[0];
    for(int i=1;i<n*m;i++){
            cin>>a[i];
            c=max(b,a[i]);
            if(c==b){
                cs++;
                break;
            }
            cs++;
    }
    for(int c=1;c<=m;c++){
        if(c%2==1){
            for(int r=1;r<=n;r++){
                zw++;
                if(zw==cs){
                    cout<<c<<" "<<r;
                }
            }
        }
        else{
            for(int r=n;r>=1;r--){
                zw++;
                if(zw==cs){
                    cout<<c<<" "<<r;
                }
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

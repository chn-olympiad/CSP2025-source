#include<iostream>
using namespace std;
long long a[105][105],m,n,c,r,s;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[n][m];
            if(s==0){
                s=a[n][m];
                c=1;
                r=1;
            }
            if(a[m][n]>s){
                if(c%2==1){
                    if(r==n)
                        c++;
                    else
                        r++;
                }
                else{
                    if(r==1)
                        c++;
                    else
                        r--;
                }
            }
        }
    }
    cout<<c<<' '<<r;
    return 0;
}

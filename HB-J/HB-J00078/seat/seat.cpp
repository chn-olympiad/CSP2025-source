#include <bits/stdc++.h>
using namespace std;
bool sh(int a,int b){
if(a>b){
    return true;
}
return false;
}

int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int a[110];
int m,n,r;
cin>>m>>n;
for(int i=1;i<=m*n;i++){
    cin>>a[i];
}
r=a[1];
sort(a+1,a+1+m*n,sh);
for(int i=1;i<=m*n;i++){
    if(a[i]==r){
        if(i%n==0){
            if((i/n)%2==1){
                cout<<i/n<<' '<<n;
            }
            else{
                cout<<i/n<<' '<<1;
            }
        }
        else{
            if((i/n)%2==0){
                cout<<i/n+1<<' '<<i%n;
            }
            else{
                cout<<i/n+1<<' '<<n-(i%n-1);
            }
        }
        break;
    }
}

return 0;
}

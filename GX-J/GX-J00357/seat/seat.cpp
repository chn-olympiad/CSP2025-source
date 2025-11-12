#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
long long n,m,a[N],a1,n1 = 1,m1 = 1,num;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i<=n*m;i++){
        cin>>a[i];
    }
    a1 = a[1];
    sort(a+1,a+n*m+1);
    for(int i = n*m;i>=1;i--){
        if(a1 == a[i]){
            cout<<m1<<" "<<n1;
            break;
        }
        if(m1%2==1){
            n1++;
            if(n1>n){
                m1++;
                n1 = n;
            }
        }
        else if(m1%2==0){
            n1--;
            if(n1<1){
                n1 = 1;
                m1++;
            }
        }
    }
    return 0;
}

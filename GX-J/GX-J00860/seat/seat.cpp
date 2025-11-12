#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    long long n,m,x;
    cin>>n>>m;
    long long a[105];
    long long s=n*m,mx=-1;
    for(int i=1;i<=s;i++){
        cin>>a[i];
        x=a[1];
        if(a[i]>mx) mx=a[i];
    }
    for(int i=1;i<=s;i++){
        if(1+mx-x<=m){
            n=mx-x+1;
            cout<<1<<' '<<n<<endl;
            return 0;
        }else if(1+mx-x>m){
            m=(1+mx-x)/m+1;
            if(m%2==0){
                n=mx-x-1;
                cout<<m<<' '<<n<<endl;
                return 0;
            }else{
                n=(mx-x)/m;
                cout<<m<<' '<<n<<endl;
                return 0;
            }
        }
    }
    return 0;
}

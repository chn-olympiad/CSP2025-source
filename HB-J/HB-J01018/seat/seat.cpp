//#Shang4Shan3Ruo6Shui4
#include<bits/stdc++.h>
using namespace std;
int a[10000];
//2 2
// 98 99 100 97
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,s;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];

    }
    s=a[1];
    sort(a+2,a+n*m+1);
    int t=n*m;
    for(int i=2;i<=n*m;i++){
        if(a[i]<s){
            t--;
        }

    }
    int t2=t%n;
    if(t2!=0){
        if(((t-t2)/n)%2==0){
            cout<<(t-t2)/n+1<<" "<<t2;
        }
        else{
            cout<<(t-t2)/n+1<<" "<<n+1-t2;
        }
    }
    else{
        if((t/n)%2==0){
            cout<<t/n<<" "<<1;
        }
        else{
            cout<<t/n<<" "<<n;
        }
    }
    return 0;
    }



#include<bits/stdc++.h>
using namespace std;
int s;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[101];
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int k=a[1];
    int b[101];
    for(int i=1;i<=n*m;i++){
        s=0;
        for(int j=1;j<=n*m;j++){
            if(a[j]>s){
                s=a[j];
            }
        }
        for(int j=1;j<=n*m;j++){
            if(a[j]==s){
                b[i]=a[j];
                a[j]=0;
                break;
            }
        }
    }
    for(int i=1;i<=n*m;i++){
        if(k==b[i]){
            s=i;
            break;
        }
    }
    if(s%n==0){
        if(s/n%2==0){
            cout<<s/n<<" "<<1;
        }
        else{
            cout<<s/n<<" "<<n;
        }
    }
    else{
        if(s/n%2==0){
            cout<<s/n+1<<" "<<s%n;
        }
        else{
            cout<<s/n+1<<" "<<n-(s%n)+1;
        }
    }
    return 0;
}

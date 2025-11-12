#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[101],b=0,s=1;
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>a[i];
        if(a[0]<a[i]){
            s++;
        }
    }
    if(s%n==0){
        if((s/n)%2==0){
            cout<<s/n<<" "<<s%n;
        }else{
            cout<<s/n<<" "<<n-s%n;
        }
    }else{
        if(s%n==1){
            if((s/n)%2==0){
                cout<<s/n+1<<" "<<s%n;
            }else{
                cout<<s/n+1<<" "<<n-s%n;
            }
        }else{
            if((s/n)%2==0){
                cout<<s/n+1<<" "<<s%n;
            }else{
                cout<<s/n+1<<" "<<n-s%n;
            }
        }
    }
    return 0;
}


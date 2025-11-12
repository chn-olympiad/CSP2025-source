#include<bits/stdc++.h>
using namespace std;
int n,m,j,big,t;
int main(){
    freopen("number","r",stdin);
    freopen("number.out","w",stdout);
    cin>>n>>m;
    int a[n*m+1],b[n*m+1];
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    j=a[1];
    for(int i=1;i<=n*m-1;i++){
        if(a[i+1]>a[i]){
            big=a[i+1];
            a[i+1]=a[i];
            a[i]=big;
        }
    }
    for(int i=1;i<=n*m;i++){
        if(a[i]==j){
            t=a[i];
        }
    }
    if(t<=n){
        cout<<1<<" "<<t;
    }else {
        if(n%2==0){
                if(t/n!=0){
                        if(t-n==n){
                            cout<<t/n+1<<" "<<1;
                        }else if(t-n>2){
                            cout<<t/n+1<<" "<<t-n-1;
                        }else if(t-n>1&&t-n<2){
                            cout<<t/n+1<<" "<<t-n+1;
                        }else{
                            cout<<t/n+1<<" "<<t-n+2;
                        }
                }else{
                        if(t-n==n){
                            cout<<t/n<<" "<<1;
                        }else if(t-n>2){
                            cout<<t/n<<" "<<t-n-1;
                        }else if(t-n>1&&t-n<2){
                            cout<<t/n<<" "<<t-n+1;
                        }else{
                            cout<<t/n<<" "<<t-n+2;
                        }
                }
        }else{if(t/n!=0){
                        if(t-n==n){
                            cout<<t/n+1<<" "<<1;
                        }else if(t-n>2){
                            cout<<t/n+1<<" "<<t-n-1;
                        }else if(t-n>1&&t-n<2){
                            cout<<t/n+1<<" "<<t-n+1;
                        }else{
                            cout<<t/n+1<<" "<<t-n+2;
                        }
                }else{
                if(t/n!=0){
                        if(t-n==n){
                            cout<<t/n<<" "<<1;
                        }else if(t-n>2){
                            cout<<t/n<<" "<<t-n-1;
                        }else if(t-n>1&&t-n<2){
                            cout<<t/n<<" "<<t-n+1;
                        }else{
                            cout<<t/n<<" "<<t-n+2;
                        }
                }

            }
        }
    }
    return 0;
}

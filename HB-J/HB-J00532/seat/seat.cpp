#include<bits/stdc++.h>
using namespace std;
int n,m,s[105],d,c,a;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    c=n*m;
    for(int i=1;i<=c;i++){
        cin>>s[i];
    }
    d=s[1];
    sort(s+1,s+1+c);
    for(int i=1;i<=c;i++){
        if(s[i]==d){
            a=c-i+1;
            int b=a/n;
            if(a<=n){
                cout<<"1"<<" "<<a;
                return 0;
            }
            if(a>n&&a%n!=0&&b%2==0){
                cout<<b+1<<" "<<a%n;
                return 0;
            }
            if(a>n&&a%n!=0&&b%2!=0){
                cout<<b+1<<" "<<n-a%n+1;
                return 0;
            }
            if(a>n&&a%n==0&&b%2==0){
                cout<<b<<" "<<"1";
                return 0;
            }
            if(a>n&&a%n==0&&b%2!=0){
                cout<<b<<" "<<n;
                return 0;
            }
        }
    }
}

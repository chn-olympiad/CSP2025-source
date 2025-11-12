#include<bits/stdc++.h>
using namespace std;

int a[105];

bool cmp(int x,int y){
    return x>y;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int num=a[1];
    sort(a+1,a+n*m+1,cmp);

    int c,r;
    for(int i=0;i<n*m;i++){
        if(a[i]==num){
            if(i%n){
                c=i/n+1;
                if(c%2){
                    r=i%n;
                    if(!r){
                        r=n;
                    }
                }
                else r=n-i%n+1;
            }
            else {
                c=i/n;
                if(c%2){
                    r=i%n;
                    if(!r){
                        r=n;
                    }
                }
                else r=n-i%n+1;
            }
        }
    }
    cout<<c<<" "<<r;

    return 0;
}


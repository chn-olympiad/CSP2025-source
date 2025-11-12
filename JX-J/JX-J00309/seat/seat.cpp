#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int x=n*m;
    int a[x+1];
    for(int i=1;i<=x;i++){
        cin>>a[i];
    }
    int R=a[1];
    sort(a+1,a+x+1,cmp);
    int c=1,r=1,p=1,sz=1;
    while(1){
        if(a[sz]==R){
            cout<<r<<" "<<c;
            return 0;
        }
        if(p){
            c++;
            if(c>n){
                c=n;
                p=0;
                r++;
            }
        }else{
            c--;
            if(c<1){
                c=1;
                p=1;
                r++;
            }
        }
        sz++;
    }
    return 0;
}

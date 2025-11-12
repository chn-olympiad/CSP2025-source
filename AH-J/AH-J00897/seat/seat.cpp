#include<bits/stdc++.h>
using namespace std;
int m,n,b,c,d=1;
int a[105];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    b=a[0];
    sort(a,a+m*n,cmp);
    for(int i=0;i<m*n;i++){
        if(a[i]==b){
            c=i+1;
        }
    }
    while(d){
        if(d%2!=0){
            if(c>m){
                c-=m;
            }else if(c==m){
                cout<<d<<" "<<m;
                break;
            }else{
                cout<<d<<" "<<c;
                break;
            }
        }else if(d%2==0){
            if(c>m){
                c-=m;
            }else if(c==m){
                cout<<d<<" 1";
                break;
            }else{
                cout<<d<<" "<<1+m-c;
                break;
            }
        }
        d++;
    }
}

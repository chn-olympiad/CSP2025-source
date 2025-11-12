#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,q=1,p=1,an=1;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int num=a[1];
    sort(a+1,a+n*m+1,cmp);
    while(1){
        if(p>n){
            p=n;
            q++;
        }
        else if(p==0){
            p=1;
            q++;
        }
        if(q%2!=0){
            if(a[an]==num){
                cout<<q<<" "<<p;
                return 0;
            }
            an++;
            p++;
        }
        else{
            if(a[an]==num){
                cout<<q<<" "<<p;
                return 0;
            }
            an++;
            p--;
        }
    }
    return 0;
}

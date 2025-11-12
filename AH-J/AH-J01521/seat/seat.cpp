#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[150];
bool cmp(int a,int b){
    return a>b;
}
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int a1=a[1];
    sort(a+1,a+1+n*m,cmp);
    if(a[1]==a1){
        cout<<"1 1";
        return 0;
    }
    int hang=1,lie=1;
    bool b=0;
    bool dc=0;
    bool w11=0;
    for(int i=2;i<=n*m;i++){
        if(dc==1){
            lie++;
            dc=0;
        }else{
            dc=0;
            if(b==0) hang++;
            else hang--;
            if(hang==n){
                b=1;
                dc=1;
            }
            if(hang==1){
                b=0;
                dc=1;
            }
        }
        if(a[i]==a1){
            break;
        }

    }
    cout<<lie<<" "<<hang;
    return 0;
}

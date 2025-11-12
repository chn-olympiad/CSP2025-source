#include<bits/stdc++.h>
using namespace std;
int a[100000];
int n,m,r;
bool cmp(int p,int ne){
    return p>ne;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int t=n*m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    r=a[1];
    sort(a+1,a+t+1,cmp);
    int ni=1,mi=1;
    for(int i=1;i<=n*m;i++){
        if(a[i]==r){
            cout<<mi<<' '<<ni;
            return 0;
        }
        if(ni==n){
            mi++;
            ni=1;
        }
        else{
            ni++;
        }
    }

    return 0;
}

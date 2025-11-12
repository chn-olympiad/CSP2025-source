#include<bits/stdc++.h>
using namespace std;
int n,m,a[1009],r;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;++i)
        cin>>a[i];
    r=a[1];
    sort(a+1,a+n*m+1,cmp);
    int h=1,l=1;
    for(int i=1;i<=n*m;++i){
        if(a[i]==r){
            cout<<l<<' '<<h;
            break;
        }
        if(l%2==1)
            h++;
        else
            h--;
        if(h>n)
            h=n,l++;
        if(h<1)
            h=1,l++;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,m;
int st;
struct S{
    int s,p;
}a[1006];
bool cmp(S x,S y){
    return x.s>y.s;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    cin>>n>>m;
    st=n*m;
    for(int i=1;i<=st;i++){
        cin>>a[i].s;
        a[i].p=i;
    }
    sort(a+1,a+st+1,cmp);
    int h=1,l=1;
    int f=1;
    for(int i=1;i<=st;i++){
        if(a[i].p==1){
            cout<<l<<' '<<h;
            break;
        }
        if(h+f>n||h+f<1){
            f=-f;
            l++;
        }
        else{
            h+=f;
        }

    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
bool cmp(int q,int p){
    return q>p;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int H,L;
    cin>>H>>L;
    int ren=H*L;
    int a[ren];
    for(int i=0;i<ren;i++)
        cin>>a[i];
    int t=a[0];
    sort(a,a+ren,cmp);
    float R=0;
    for(int i=0;i<ren;i++){
        if(a[i]==t)
            R=i+1;
    }
    int l=0,h=0;
    l=ceil(R/L);
    h=H-(int)R%H+1;
    if((int)R%H==0)h=L;
    if(l%2==1)h=(int)R%H;
    if(R<=H){
        l=1;
        h=R;
    }
    cout<<l<<" "<<h;
    return 0;
}

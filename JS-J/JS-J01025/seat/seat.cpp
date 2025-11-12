#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int n,m,ls[101],temp,pos;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>ls[i];
        if (i==1){
            temp=ls[i];
        }
    }
    sort(ls+1,ls+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if (ls[i] == temp){
            pos=i;
            break;
        }
    }
    int t2=pos / n + 1,t1;
    if (t2 % 2 == 0){
        t1=1+(t2*n-pos);
    }
    else{
        t1=n-(t2*n-pos);
    }
    if (t1 > n){
        t2--;
        t1--;
    }
    else{
        if (t1 <= 0){
            t2--;
            t1++;
        }
    }
    cout<<t2<<" "<<t1;
}

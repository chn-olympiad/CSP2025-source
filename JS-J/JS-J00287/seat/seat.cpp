#include<bits/stdc++.h>
using namespace std;
int n,m,lst[105];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int k=n*m;
    for(int i=1;i<=k;i++){
        cin>>lst[i];
    }
    int a=lst[1];
    sort(lst+1,lst+1+k,cmp);
    int num=0;
    for(int i=1;i<=k;i++){
        if(lst[i]==a) num=i;
    }
    int l,h;
    if(num%n!=0){
        l=num/n+1;
    }
    else l=num/n;
    cout<<l<<' ';
    if(num%n!=0){
        if(l%2==0) cout<<n-(num%n)+1;
        else cout<<num%n;
    }
    else{
        if(l%2==0) cout<<1;
        else cout<<n;
    }
    return 0;
}

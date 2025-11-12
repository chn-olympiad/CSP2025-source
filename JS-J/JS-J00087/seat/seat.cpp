#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int a[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int all=n*m;
    for(int i=1;i<=all;i++)
        cin>>a[i];
    int x=a[1],number;
    sort(a+1,a+all+1,cmp);
    for(int i=1;i<=all;i++){
        if(a[i]==x){
            number=i;
        break;
        }
    }
    int z=n*2;
    int g1=number/z,g2=number%z;
    if(g2>n){
        cout<<g1*2+2<<" ";
        cout<<n-(g2-n)+1;
    }
    else{
        cout<<g1*2+1<<" ";
        cout<<g2;
    }
    return 0;
}

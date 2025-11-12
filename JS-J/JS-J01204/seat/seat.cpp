#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    int n,m;
    int a[101]={0};
    int a1;
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        int b;
        cin>>b;
        if(i==0){
            a1=b;
        }
        a[b]++;
    }
    int pm=1;
    for(int i=100;i>a1;i--){
        if(a[i]>0){
            pm++;
        }
    }
    int l,h;
    l=pm/n+(pm%n>=1);
    if(l%2==1){
        h=(pm-1)%n+1;
    }else{
        h=m-(pm-1)%n;
    }
    cout<<l<<' '<<h;
    return 0;
}


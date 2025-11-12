#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,ai,p=1;
    cin>>n>>m;
    int q=n*m,a[q];
    for(int i=0;i<q;i++){
        cin>>a[i];
    }
    ai=a[0];
    for(int i=0;i<q;i++){
        if(a[i]>ai){
            p++;
        }
    }
    int w=p/n,e=p%n;
    if(e==0){
        cout<<w<<" "<<n;
    }
    else{
        cout<<w+1<<" ";
        if((w+1)%2!=0){
            cout<<e;
        }
        else{
            cout<<n-e+1;
        }
    }
    return 0;
}

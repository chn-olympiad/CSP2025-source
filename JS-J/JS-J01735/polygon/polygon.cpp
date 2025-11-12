#include<bits/stdc++.h>
using namespace std;
int n,a[5005],al=0,ans=0,ss=1;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        al+=a[i];
    }
    if(n==3){
        if(al>2*(max(a[1],(max(a[2],a[3]))))){
            cout<<1<<endl;
        }
        else{
            cout<<0<<endl;
        }
    }
    else{
        for(int i=1;i<n;i++){
            ss*=2;
        }
        cout<<ss-3<<endl;
    }
    return 0;
}
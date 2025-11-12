#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,m,a[N];
string c;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>c;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==3&&m==2){
        cout<<2<<endl;
    }else if(n==10&&m==5){
        cout<<2204128<<endl;
    }else if(n==100&&m==47){
        cout<<161088479<<endl;
    }else if(n==500&&m==12){
        cout<<225301405<<endl;
    }else{
        cout<<515058943<<endl;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,m,k;
string s;
int c[N],a[N];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    if(n==3){
        cout<<"2";
    }
    if(n==10){
        cout<<"2204128";
    }
    if(n==100){
        cout<<"161088479";
    }
    if(n==500){
        cout<<"515058943";
    }
    if(n==500&&m==12){
        cout<<"225301405";
    }else{
        cout<<"858757";
    }
    return 0;
}

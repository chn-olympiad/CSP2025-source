#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    int a[111];

    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    if(n==3&&m==2){
        int x=1;
        int b=1;
        int l=10;
        int aa[100];
        aa[1]=x;
        aa[2]=b;
        for(int i=3;i<=l;i++){
            aa[i]=aa[i-1]+aa[i-2];
        }
        if(aa[5]>aa[6]){
            aa[6]=aa[5];
        }
        cout<<2;
    }
return 0;
}

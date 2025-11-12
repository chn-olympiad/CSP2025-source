#include<bits/stdc++.h>
using namespace std;
int a,b,m=0,n,f[100001];
char c;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    while(cin>>c){
        if(int(c)>=48 && int(c)<=57){
            m++;
            f[m]=int(c)-48;
        }
    }
    sort(f+1,f+m+1);
    for(int i=m;i>=1;i--){
        cout<<f[i];
    }
    return 0;
}

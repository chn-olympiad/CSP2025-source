#include <bits/stdc++.h>
using namespace std;
char a[10000];
char b[10000],c[10000];
bool f=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
       for(int i=0;a[i];i++){
        if(a[i]<'0'&&a[i]>'9'){
        continue;
        }
        else{
        b[i]=a[i];
        }
       }
    for(int i=0;a[i];i++){
        c[i]=b[i];
        if(b[i]<b[i+1]){
            b[i]=b[i+1];
            b[i+1]=c[i];
        }
   }
    for(int i=0;a[i];i++){
        if(b[i]>='0'&&b[i]<='9'){
        cout<<b[i];
        }
    }
    return 0;
}

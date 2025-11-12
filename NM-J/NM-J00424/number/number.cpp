#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a="";
    int b=0,c[11]={0};
    cin>>a;
    a=a+' ';
    while(1==1){
        if(a[b]>='0' && a[b]<='9'){
            c[int(a[b])-48]+=1;
        }
        b+=1;
        if(a[b]==' ') break;
    }
    for(int i=10;i>=0;i--){
        for(int j=0;j<c[i];j++){
            cout<<i;
        }
    }
    return 0;
    fclose(stdin);
    fclose(stdout);
}

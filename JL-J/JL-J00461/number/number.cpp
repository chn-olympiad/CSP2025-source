#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int a[100],b,i=0,j=0;
    char  c[100];
    cin>>c;
    while(c[i]!='/n'){
            if(c[i]-'0'>=0 && c[i]-'0'<=9){
                a[j]=c[i]-'0';j++;
            }
            i++;
    }
    for(int k=0;k<=j;k++){
        cout<<a[k];
    }
    return 0;
}

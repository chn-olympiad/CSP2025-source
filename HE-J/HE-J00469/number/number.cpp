#include<bits/stdc++.h>
//ppppp
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    char a[10];
    cin>>a;
    for(int i=0;i<10;i++){
        if(a[i]>='0' || a[i]<='9') cout<<a[i];
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}

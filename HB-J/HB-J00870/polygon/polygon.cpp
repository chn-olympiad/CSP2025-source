#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("polygon1.in","r",stdin);
    freopen("polygon1.out","w",stdout);
    int n;
    cin>>n;
    int a[n];
    if(a[0]+a[1]>a[2]){
        cout<<1<<endl;
    }else{
        cout<<0<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}


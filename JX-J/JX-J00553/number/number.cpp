#include<bits/stdc++.h>
using namespace std;
int b[20];
int main(){
    string a;
    int z=0;
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    for(int i=0;i<a.size();i++){
        if(a[i]>='0' && a[i]<='9'){
            b[(int)a[i]-48]++;
        }
    }
    for(int i=9;i>=0;i--){
        while(b[i]){
            cout<<i;
            b[i]--;
        }
    }
    cout<<z;
    return 0;

    }

#include <bits/stdc++.h>
using namespace std;
bool k(int a,int b){
    return a>b;
}
int b[100005];
int main(){
    string a;
    cin>>a;
    int z = 0;
    for(int i = 0;i <= a.size();i++){
        if(a[i] >= '0' and a[i] <='9'){
            b[i] = a[i]-'0';
            z++;
        }

    }
    sort(b,b+a.size(),k);
    int maxx = 0;
   /* for(int i = 0;i <= a.size();i++){
        for(int j = i;j <= a.size();j++){
            if(b[j] > b[i]) swap(b[i],b[j]);
        }
    }*/
    for(int i = 0;i < z;i++){
        cout<<b[i];
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int b=1;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string x;
    cin>>x;
    for(int i=0;i<x.size();i++){
        if(x[i]>='0'&&x[i]<='9'){
            a[b]=int(x[i]-'0');
            b++;
        }
    }
    sort(a+1,a+b);
    for(int i=b-1;i>0;i--){
        cout<<a[i];
    }
    return 0;
}

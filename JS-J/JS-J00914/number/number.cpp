#include<bits/stdc++.h>
using namespace std;
int x[1000006];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a,b="";
    int num=0;
    cin>>a;
    for(int i=0;i<a.size();++i){
        x[i]=a[i];
    }
    sort(x,x+a.size());
    for(int i=a.size()-1;i>=0;--i){
        if(x[i]>='0' and x[i]<='9'){
            b+=char(x[i]);
        }
    }
    cout<<b;
    return 0;
}

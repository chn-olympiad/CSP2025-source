#include <bits/stdc++.h>
using namespace std;
int b[1000100];
bool cmp(int a,int b){
     return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;
    int s=0;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]-48<=9){
            b[i]=a[i]-48;
        }
        if(a[i]-48>9){
            s++;
        }
    }
    sort(b,b+a.size(),cmp);
    for(int i=0;i<a.size()-s;i++){
        cout<<b[i];
    }
    return 0;
}

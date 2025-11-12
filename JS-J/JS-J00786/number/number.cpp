#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string n;
    int a[1011111];
    cin>>n;
    int t=0;
    int ln=n.length();
    for(int i=0;i<=ln;i++){
        if(int(n[i])>=48&&int(n[i])<=57){
            a[t]=int(n[i])-48;
            t++;
        }
    }
    sort(a,a+t,cmp);
    for(int i=0;i<t;i++){
        cout<<a[i];
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
string a;
int n[1000000];
int b=0;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    for(int i=0;i<=a.size();i++){
        if(a[i]<='9' && a[i]>='0'){
            n[b]=a[i]-'0';

            b+=1;
        }
    }
    sort(n,n+b,cmp);
    for(int i=0;i<b;i++){

        cout<<n[i];

    }
    return 0;
}

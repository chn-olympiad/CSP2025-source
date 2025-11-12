#include<bits/stdc++.h>
using namespace std;
int t[1000005];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;
    int cnt=0;
    for(int i=0;i<a.size();i++){
        if(a[i]>='0'&&a[i]<='9'){
            t[++cnt]=a[i]-'0';
        }
    }
    sort(t+1,t+1+cnt,cmp);
    for(int i=1;i<=cnt;i++){
         cout<<t[i];
    }
    return 0;
}/*

*/

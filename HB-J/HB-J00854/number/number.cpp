#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    int n[1000005],cnt=1;
    cin>>a;
    for(int i=0;i<a.length();i++){
        if(a[i]<='9'&&a[i]>='0'){
            n[cnt]=a[i]-'0';
            cnt++;
        }
    }
    sort(n+1,n+cnt,cmp);
    for(int i=1;i<cnt;i++){
        cout<<n[i];
    }
}

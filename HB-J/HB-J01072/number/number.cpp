#include<bits/stdc++.h>
#define int long long
using namespace std;
string a;
int b[1000010]={},len=0;
bool cmp(int a,int b){
    return a>b;
}
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    for(int i=0;i<a.length();i++){
        if(a[i]>='0'&&a[i]<='9'){
            b[len++]=a[i]-'0';
        }
    }sort(b,b+len,cmp);
    for(int i=0;i<len;i++){
        cout<<b[i];
    }cout<<endl<<len;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

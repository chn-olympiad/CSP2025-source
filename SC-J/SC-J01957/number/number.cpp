#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+7;
string a;
int b[MAXN],cnt;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    int lena=a.length();
    for(int i=0;i<lena;i++){
        if(a[i]>='0'&&a[i]<='9'){
            b[cnt++]=a[i]-'0';
        }
    }
    sort(b,b+cnt,cmp);
    if(b[0]==0){
        cout<<0;
    }
    else{
        for(int i=0;i<cnt;i++){
            cout<<b[i];
        }
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
bool cmp(int x1,int y1){
    return x1>y1;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;
    int l[120000],len,x=0;
    len=a.size();
    for(int i=0;i<len;i++){
        if(a[i]>='0'&&a[i]<='9'){
            l[x]=(int)(a[i]-'0');
            x++;
        }
    }
    sort(l,l+x,cmp);
    for(int i=0;i<x;i++){
        cout<<l[i];
    }
    return 0;
}

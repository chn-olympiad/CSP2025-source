#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010],x=0,y=0,z=0;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>s;
    int l=s.size();
    for(int i=0;i<l;i++){
        if(s[i]>='0'&&s[i]<='9')a[x++]=s[i]-'0';
    }
    sort(a,a+x,cmp);
    if(a[0]==0){
        cout<<0;
        return 0;
    }
    for(int i=0;i<x;i++){
        cout<<a[i];
    }
    return 0;
}

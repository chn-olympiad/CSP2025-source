#include<bits/stdc++.h>
using namespace std;
string s;
int a[1111111];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int x=s.size();
    if(x==1){
        cout<<s;
        return 0;
    }
    int j=0;
    for(int i=0;i<x;i++){
        if(isdigit(s[i])){
            j++;
            a[j]=s[i]-'0';
        }
    }
    sort(a+1,a+1+j,cmp);
    for(int i=1;i<=j;i++) cout<<a[i];
    return 0;
}

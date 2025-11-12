#include<bits/stdc++.h>
using namespace std;
long long asd(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.ans","w",stdout);
    string a;
    cin>>a;
    long long s[1005],x=0;
    for(int i=0;i<a.length();i++){
        if(a[i]-'0'>=0 && a[i]-'0'<=9){
            s[i]=a[i]-'0';
            x++;
        }
    }
    sort(s,s+a.length(),asd);
    for(int i=0;i<x;i++){
        cout<<s[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

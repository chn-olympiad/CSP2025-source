#include<bits/stdc++.h>
using namespace std;
string a;
bool cmp(char a,char b){
    return a>b;
}
int  main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    sort(a.begin(),a.end(),cmp);
    for(int i=0;i<a.size();i++){
        if(a[i]<='9'&&a[i]>='0')cout<<a[i];
    }
    return 0;
}

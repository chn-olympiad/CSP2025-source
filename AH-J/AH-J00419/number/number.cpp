#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
string a,b;
bool cmp(char x,char y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    b="";
    for(int i=0;i<a.size();i++){
        if(a[i]>='0'&&a[i]<='9') b+=a[i];
    }
    sort(b.begin(),b.end(),cmp);
    cout<<b;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

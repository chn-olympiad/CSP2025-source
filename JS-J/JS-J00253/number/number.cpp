#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int a[1000010],siz=0;
    for(int i=0;i<(int)s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[siz++]=s[i]-'0';
        }
    }
    sort(a,a+siz);
    int b[1000010],sizz=0;
    for(int i=siz-1;i>=0;i--){
        b[sizz++]=a[i];
    }
    int c=sizz-1;
    for(int i=0;i<sizz-1;i++){
        if(b[i]!=0){
            c=i;
            break;
        }
    }
    for(int i=c;i<sizz;i++){
        cout<<b[i];
    }
    return 0;
}
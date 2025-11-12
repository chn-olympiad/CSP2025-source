#include<bits/stdc++.h>
using namespace std;
int main(){
    int n=2;
    int a[1000000]={-1};
    for(int c=0;c<1000000;c++){
        a[c]=-1;
    }
    int YSy[10]={99,99,99,99,99,99,99,99,99,99};
    char s[1000000]={0};
    for(int c=0;c<n;c++){
        cin>>s[c];
         n++;
    }
    for(int c=0;c<1000000;c++){
        if(s[c]>='a' && s[c]<='z')
            continue;
        if(s[c]=='0')
            a[c]=0;
        if(s[c]=='1')
            a[c]=1;
        if(s[c]=='2')
            a[c]=2;
        if(s[c]=='3')
            a[c]=3;
        if(s[c]=='4')
            a[c]=4;
        if(s[c]=='5')
            a[c]=5;
        if(s[c]=='6')
            a[c]=6;
        if(s[c]=='7')
            a[c]=7;
        if(s[c]=='8')
            a[c]=8;
        if(s[c]=='9')
            a[c]=9;
    }
    int i=0;
    sort(a,a+1000000);
    for(int u=999999;u>=0;u--){
        if(a[u]==-1){
        break;
        }
        else{
            cout<<a[u];
        }
    }
    return 0;
}

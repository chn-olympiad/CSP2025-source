#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;
    int c=0,b=a.size(),s[1000005];
    for(int i=0;i<b;i++){
        if(int(a[i])-48>=0&&int(a[i])-48<=9){
            s[c]=int(a[i])-48;
            c++;
        }
    }
    sort(s,s+c);
    for(int i=c-1;i>=0;i--)cout<<s[i];
    return 0;
}

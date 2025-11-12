#include<bits/stdc++.h>
using namespace std;
string a;
char s[1000005];
bool cmp(char a,char b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int cnt=0;
    cin>>a;
    for(int i=0;i<a.size();i++){
        if(a[i]>='0'&&a[i]<='9'){
            s[++cnt]=a[i];
        }
    }
    sort(s+1,s+1+cnt,cmp);
    for(int i=1;i<=cnt;i++){
        cout<<s[i];
    }
    return 0;
}

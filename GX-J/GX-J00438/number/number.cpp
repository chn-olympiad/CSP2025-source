#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int a[1000002]={0},ans=0;a[0]=100000;
    char s[1000002];
    cin>>s+1;
    int x=sizeof(s);
    for(int i=1;i<=x;i++){
        if(s[i]!=' '&&int(s[i])-48>=0&&int(s[i])-48<=9){
            ans++;
            a[s[i]]=int(s[i])-48;
        }
        else{
            if(s[i]!=' '){
                continue;
            }
            break;
        }
    }
    sort(a+1,a+ans+1,cmp);
    for(int i =1;i<=ans;i++){
        cout<<a[i];
    }
    return 0;
}

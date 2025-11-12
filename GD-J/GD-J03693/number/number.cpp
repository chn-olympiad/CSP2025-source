#include<bits/stdc++.h>
using namespace std;
char a[1000005];
int b[1000005];
string s;
bool cmp(int a,int b){
    if(a<b)return 0;
    return 1;
}
int ans=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int f=1;
    cin>>s;
    for(int i=1;i<=s.size();i++){
        a[i]=s[i-1];
    }
    for(int i=1;i<=s.size();i++){
        int tem=a[i]-'0';
        if(tem<=9&&tem>=0){
            b[f]=tem;
            f++;
        }
    }
    sort(b+1,b+f,cmp);
    for(int i=1;i<=f-1;i++){
        cout<<b[i];
    }
    return 0;
}


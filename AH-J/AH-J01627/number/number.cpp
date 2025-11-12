#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],t;
int cmp(int a,int b){
    return a>b;	
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    memset(a,0,sizeof(a));
    cin>>s;
    int len=s.size();
    for(int i=0;i<len;i++)
        if('0'<=s[i]&&s[i]<='9'){a[i]=s[i]-'0';t++;}
    sort(a+0,a+len,cmp);
    for(int i=0;i<t;i++)cout<<a[i];
    return 0;
}

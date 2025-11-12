#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(char n1,char n2){
    return (n1>n2);
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    char s[1000001],dg[1000001];
    cin>>s;
    int n=strlen(s),cnt=0;
    for(int i=0;i<n;i++) if(s[i]>='0'&&s[i]<='9') dg[cnt++]=s[i];
    sort(dg,dg+cnt,cmp);
    cout<<dg;
    return 0;
}

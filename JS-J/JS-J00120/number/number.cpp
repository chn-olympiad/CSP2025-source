#include<bits/stdc++.h>
using namespace std;
int a[1000010];
string s;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int j=0;
    for(int i=0;i<s.size();i++)if(s[i]>='0'&&s[i]<='9')a[j++]=s[i]-'0';
    sort(a,a+j,cmp);
    bool flag=0;
    for(int i=0;i<j;i++){
        if(a[i])flag=1;
        if(flag)cout<<a[i];
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
string s;
char a[1000005];
int cnt;
bool cmp(char x,char y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>s;
    for(int i=0;s[i]!='\0';i++){
        if(s[i]>='0'&&s[i]<='9')
            a[cnt++]=s[i];
    }
    sort(a,a+cnt,cmp);
    if(a[0]=='0') cout<<0;
    else for(int i=0;i<cnt;i++) cout<<a[i];
    return 0;
 }

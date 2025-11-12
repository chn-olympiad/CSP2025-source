#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int num[N];
int cnt;
string s;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int len=s.size();
    s="x"+s;
    for(int i=1;i<=len;i++){
        if(s[i]>='0'&&s[i]<='9') num[++cnt]=s[i]-'0';
    }
    sort(num+1,num+1+cnt,cmp);
    for(int i=1;i<=cnt;i++) cout<<num[i];
    return 0;
}

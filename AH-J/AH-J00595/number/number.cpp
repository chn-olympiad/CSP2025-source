#include<bits/stdc++.h>
using namespace std;
string s;
int num[1000010],cnt;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<int(s.size());i++){
        if(isdigit(s[i])) num[++cnt]=int(s[i]-'0');
    }
    sort(num+1,num+1+cnt);
    for(int i=cnt;i>=1;i--) printf("%d",num[i]);
    return 0;
}
/*
ez 直接颗秒

六百六十六 我竟然能用中文输入法
*/

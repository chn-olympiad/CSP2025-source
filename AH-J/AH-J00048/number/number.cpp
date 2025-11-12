#include<bits/stdc++.h>
using namespace std;
string s;
long long a[100050],flag=0,cnt=0;
bool cmp(int x,int y){
    return x>y;
}
int main(void){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int o=s.size()-1;
    for(int i=0;i<=o;i++){
        if(s[i]>='0'&&s[i]<='9'){
            cnt++;
            a[cnt]=s[i]-'0';
        }
    }
    sort(a+1,a+cnt+1,cmp);
    for(int i=1;i<=cnt;i++){
        cout<<a[i];
    }
    return 0;
    //fu ning na wai le,deng xi nuo ning ba,dan bu zhi dao du lin qiang du ru he
}

#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;cin>>s;
    int tot=0;
    for(int i=0;i<=s.size();i++)
        if(s[i]>='0'&&s[i]<='9')
            a[++tot]=s[i]-'0';
    sort(a+1,a+tot+1,cmp);
    bool flag=1;
    for(int i=1;i<=tot;i++){
        if(!a[i]&&flag)continue;
        cout<<a[i];
        flag=0;
    }
    if(flag)cout<<0;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

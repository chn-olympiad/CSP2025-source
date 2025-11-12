#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int a[maxn];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin>>s;
    s=' '+s;
    int len=s.size();
    int cnt=1;
    for(int i=1;i<=len;i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[cnt++]=s[i]-'0';
        }
    }
    sort(a+1,a+cnt,cmp);
    for(int i=1;i<=cnt-1;i++){
        cout<<a[i];
    }
    return 0;
}

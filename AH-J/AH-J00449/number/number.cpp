#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    return x>y;
}
int a[1000005];
int cnt;
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            s[i]=s[i]-'0';
            cnt++;
            a[cnt]=s[i];
        }
    }
    sort(a+1,a+1+cnt,cmp);
    for(int i=1;i<=cnt;i++){
        cout<<a[i];
    }
    return 0;
}

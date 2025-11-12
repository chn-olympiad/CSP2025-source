#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;int a[100005],idx=0;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0' && s[i]<='9'){
            a[idx++]=s[i]-'0';
        }
    }
    sort(a,a+idx,cmp);
    for(int i=0;i<idx;i++){
        cout<<a[i];
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010],idx;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]<='9'&&s[i]>='0'){
            a[idx]=int(s[i]-'0');
            idx++;
        }
    }
    sort(a,a+idx,cmp);
    for(int i=0;i<idx;i++)cout<<a[i];
    return 0;
}

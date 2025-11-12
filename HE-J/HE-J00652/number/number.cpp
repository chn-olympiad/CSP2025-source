#include<bits/stdc++.h>
using namespace std;
string s;
int num[1000001],tp=1;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(s[i]<='9'&&s[i]>='0'){
            num[tp++]=s[i]-'0';
        }
    }
    sort(num+1,num+tp,cmp);
    for(int i=1;i<tp;i++){
        cout<<num[i];
    }
    return 0;
}

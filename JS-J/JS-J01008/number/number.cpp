#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
const int MAXN=1e6+5;
int num[MAXN],cnt=0;
string s;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]<='9'&&s[i]>='0'){
            num[cnt]=s[i]-'0';
            cnt++;
        }
    }
    sort(num,num+s.size(),cmp);
    for(int i=0;i<cnt;i++){
        cout<<num[i];
    }
    return 0;
}

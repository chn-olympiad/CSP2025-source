#include<bits/stdc++.h>
using namespace std;
string s;
int s1[1000010],cnt;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0,j=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            s1[++j]=s[i]-'0';
            cnt++;
        }
    }
    sort(s1,s1+cnt,cmp);
    for(int i=0;i<cnt;i++){
        cout<<s1[i];
    }
    return 0;
}

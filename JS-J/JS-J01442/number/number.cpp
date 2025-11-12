#include<bits/stdc++.h>
using namespace std;
int sum[1000006];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int cnt=0;
    for(int i=0;i<s.size();i++){
        if('0'<=s[i] && s[i]<='9') sum[cnt++]=s[i]-'0';
    }
    sort(sum,sum+cnt,cmp);
    if(sum[0]==0) cout<<0<<endl;
    else{
        for(int i=0;i<cnt;i++) cout<<sum[i];
    }
    cout<<endl;
    return 0;
}
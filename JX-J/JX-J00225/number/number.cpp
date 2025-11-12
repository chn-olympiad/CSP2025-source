#include<bits/stdc++.h>
using namespace std;
string s;
long long num[10005],cnt=0;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    long long len=s.length();
    for(int i=0;i<len;i++){
        if(s[i]>='0'&&s[i]<='9'){
            cnt++;
            num[cnt]=s[i]-'0';
        }
    }

    sort(num+1,num+1+cnt,cmp);

    if(num[1]==0){
        cout<<"0";
        return 0;
    }
    for(int i=1;i<=cnt;i++){
        cout<<num[i];
    }
    return 0;
}

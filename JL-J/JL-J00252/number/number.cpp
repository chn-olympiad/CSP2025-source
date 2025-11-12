#include<bits/stdc++.h>
#include<string>
using namespace std;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int num[1000010];
    int ans=1;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if('0'<=s[i]&&s[i]<='9'){
            num[ans]=s[i]-'0';
            ans++;
        }
    }
    ans-=1;
    sort(num,num+ans,cmp);
    for(int i=0;i<ans;i++){
        cout<<num[i];
    }
    return 0;
}

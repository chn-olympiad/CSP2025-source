#include<bits/stdc++.h>
using namespace std;
string s;
int ans[1000005];
long long cnt;
bool cmp(int a, int b){
    return a>b;
}
int main(){
    freopen("number4.in","r",stdin);
//    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]<='9'&&s[i]>='0'){
            cnt++;
            ans[cnt]=(int)s[i];
        }
    }
    sort(ans+1,ans+cnt+1,cmp);
    for(int i=1;i<=cnt;i++){
        cout<<(char)ans[i];
    }
    return 0;
}

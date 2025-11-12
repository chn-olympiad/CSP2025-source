#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;
ll cnt=0;
struct node{
    int val;
}ans[1000006];
bool cmp(node a,node b){
    return a.val>b.val;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            ans[++cnt].val=s[i]-'0';
        }
    }
    sort(ans+1,ans+cnt+1,cmp);
    int op=0;
    for(int i=1;i<=cnt;i++){
        if(ans[i].val!=0)op=1;
    }
    if(op==0){
        cout<<0;
        return 0;
    }
    for(int i=1;i<=cnt;i++){
        cout<<ans[i].val;
    }
    return 0;
    }

#include<bits/stdc++.h>
using namespace std;
int ans[1000100];

bool cmp(int a,int b){
    return a>b;
}

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int f=0,l=0;
    cin>>s;
    while((s[l]<='9'&&s[l]>='0') || (s[l]<='z'&&s[l]>='a')) l++;
    for(int i=0;i<l;i++){
        if(s[i]<='9'&&s[i]>='0'){
            f++;
            ans[f]=s[i]-'0';
        }
    }
    sort(ans+1,ans+f,cmp);
    for(int i=1;i<=f;i++) cout<<ans[i];
    return 0;
}

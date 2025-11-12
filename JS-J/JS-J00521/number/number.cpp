#include<bits/stdc++.h>
using namespace std;
int a[1000001],cnt;
bool cmp(int q,int w){
    return q>w;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s;
    cin>>s;
    string t;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9') a[++cnt]=s[i]-'0';
    }
    int f=1;
    sort(a+1,a+cnt+1,cmp);
    for(int i=1;i<=cnt;i++){
        if(a[i]!=0){
            cout<<a[i];
            f=0;
        }
        if(i==cnt&&a[i]==0) cout<<a[i]<<endl;
        if(i!=cnt&&f==0&&a[i]==0) cout<<a[i];
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int a[1000006];
bool cmp(int x,int y){return x>y;}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    string s;
    cin>>s;
    int cnt=0;
    for(int i=0;i<s.size();i++){
        if(isdigit(s[i])){
            cnt++;
            a[cnt]=s[i]-'0';
        }
    }
    sort(a+1,a+cnt+1,cmp);
    for(int i=1;i<=cnt;i++)cout<<a[i];
    cout<<"\n";
    return 0;
}
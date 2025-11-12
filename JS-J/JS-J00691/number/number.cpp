#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
string s;
int a[maxn];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int n=s.size();
    int ans=0;
    for(int i=0;i<n;i++){
        if(s[i]-'0'<=9&&s[i]-'0'>=0){
            a[ans++]=s[i]-'0';
        }
    }
    sort(a,a+ans,cmp);
    for(int i=0;i<ans;i++){
        cout<<a[i];
    }
    return 0;
}

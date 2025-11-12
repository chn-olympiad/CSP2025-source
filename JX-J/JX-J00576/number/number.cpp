#include<bits/stdc++.h>
using namespace std;
int a[1000006];
bool cmp(int a,int b){
    return a>b;
}
int cnt;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int n=s.size();
    for(int i=0;i<n;i++){
        if(s[i]>='0'&&s[i]<='9')a[i]=s[i]-'0',cnt++;
    }
    sort(a,a+n,cmp);
    for(int i=0;i<cnt;i++)cout<<a[i];
    return 0;
}

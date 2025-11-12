#include <bits/stdc++.h>
using namespace std;
int n,ans;
int cmp(int a,int b){
    return a>b;
}
int main()
{
    string s;
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int a[s.length()+1];
    if(s.length()==1&&s[1]<=9&&s[1]>=0){
        cout<<s;
        ans++;
    }
    for(int i=0;i<s.length();i++){
        if(ans==1) break;
        if(s[i]<=9&&s[i]>=0){

            a[i]=s[i];
            n++;
        }
    }

    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++){
        if(ans==1) break;
        cout<<a[i];
    }
    return 0;
}

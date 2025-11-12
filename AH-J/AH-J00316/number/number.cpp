#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int l=s.length();
    int a[l];
    for(int i=0;i<l;i++){a[i]=-1;  if('0'<=s[i]&&s[i]<='9')a[i]=s[i]-'0';}
    sort(a,a+l+1);
    for(int i=l-1;i>=0;i--){
        if(a[i]==-1) break;
        cout<<a[i];
    }
    return 0;
}

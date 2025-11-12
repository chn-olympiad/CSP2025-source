#include <bits/stdc++.h>

using namespace std;
string s,a="0";
int ans[100002];
bool cmp(int x,int y){
    return x>y;
}
int main(){
   freopen("number.in","r",stdin);
   freopen("number.ans","w",stdout);
    cin >> s;
    int n=s.size();
    if(s>="0" && s<="9" && n==1){
        cout << s;
        return 0;
    }
    for(int i=0;i<n;i++){
        if(s[i]>='a' && s[i]<='z'){
            s[i]=' ';
        }
        if(s[i]>='0' && s[i]<='9'){
            if(a[i]<s[i]){
                a[i]=s[i];
                //cout << a[i];
                ans[i]=a[i];
            }
        }
    }

    sort(ans,ans+n,cmp);
    for(int i=0;i<n;i++){
        cout << (char)ans[i];
    }
    return 0;
}

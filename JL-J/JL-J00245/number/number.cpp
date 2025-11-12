#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin >> s;
    int a[s.size()];
    for (int i=0;i<s.size();i++){
        a[i]=-10000;
    }
    int n=0;

    for (int i=0;i<s.size();i++){
        if(s[i]<='9' && s[i]>='0'){
            a[i]=s[i];
            n++;
        }

    }
    for (int i=1;i<=n;i++){
        int maxn=-10,m=0;
        for (int j=0;j<s.size();j++){
            if(maxn<=a[j]-48){
                maxn=a[j]-48;
                m=j;
            }
        }
        if(maxn!='0') cout << maxn;
        a[m]=-1;
        int k=0;
        for (int j=0;j<s.size();j++){
            if(a[i]>=0){
                k=1;
            }
        }
        if(k=0) break;
    }

    return 0;
}

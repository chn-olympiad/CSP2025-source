#include <bits/stdc++.h>
using namespace std;
int a[100010];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int i,t=0;
    for(i=0;i<=s.size()-1;i++){
        if(s[i]>=48&&s[i]<=57){
            a[t]=s[i]-48;
            t=t+1;
        }
    }
    sort(a,a+t);
    for(i=t-1;i>=0;i--){
        cout<<a[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

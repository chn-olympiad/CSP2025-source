#include<bits/stdc++.h>
using namespace std;
int a[1000002];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int len = 0;
    for(int i=0;s[i];i++){
        if(isdigit(s[i])){
            a[++len] = int(s[i]-'0');
        }
    }
    sort(a+1,a+len+1,greater<int>());
    for(int i=1;i<=len;i++) cout<<a[i];
    cout<<1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int a[1000100];
int main(){
    freopen("number3.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int t=1;
    getline(cin,s);
    for(int i=0;i<s.size();i++){
        if(s[i]<='9'&&s[i]>='0'){
            a[t]=s[i]-'0';
            t++;
        }

    }
    sort(a+1,a+t);
    for(int i=t-1;i>=1;i--)
        cout<<a[i];
    return 0;
}

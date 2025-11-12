#include <bits/stdc++.h>

using namespace std;

int main()
{

    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int n=0,a[1000010];
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++) {
        if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
            a[n]=s[i]-48;
            n+=1;
        }
        else continue;
    }
    sort(a,a+n);
    for(int i=n-1;i>=0;i--){
        cout<<a[i];
    }
    return 0;
}

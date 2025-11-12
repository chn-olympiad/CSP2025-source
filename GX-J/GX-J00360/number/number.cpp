#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int a[100010];
    int b=0;
    int c=0;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[b]=int(s[i])-48;
            b++;
        }
    }
    sort(a,a+b);
    for(int i=b;i>=0;i--){
       c*=10;
       c+=a[i];
    }
    cout<<c;
    return 0;
}

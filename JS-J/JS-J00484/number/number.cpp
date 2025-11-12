#include <iostream>
#include <bits/stdc++.h>


using namespace std;
int a[1000009];
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
int main()
{
    string s;
    cin >> s;
    int l=s.size(),m=0;
    for (int i=0;i<l;i++){
        if(s[i]>='0' && s[i]<='9'){
            m++;
            a[m]=s[i]-'0';
        }
    }
    sort(a+1,a+m+1);
    for (int i=m;i>=1;i--){
        cout << a[i];
    }
    return 0;
}

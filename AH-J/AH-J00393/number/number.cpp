#include <bits/stdc++.h>
using namespace std;
string s;long long a[1000005],n;
int main()
{   freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
                a[i+1]=s[i]-('a'-'0');n++;
        }
    }sort(a,a+n);
    for(int i=n;i>=1;i--)cout<<a[i];
    return 0;
    fclose(stdin);
    fclose(stdout);
}

#include<bits/stdc++.h>

using namespace std;
string s;
int a[1000005],xb;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int len=s.size();
    for(int i=0;i<len;i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[xb++]=s[i] - '0';
        }
    }
    sort(a,a+xb);
    for(int i=xb-1;i>=0;i--)
        cout<<a[i];
    return 0;
}

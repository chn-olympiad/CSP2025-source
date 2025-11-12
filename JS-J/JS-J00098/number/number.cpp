#include<bits/stdc++.h>
using namespace std;
int a[100001],k;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string b;
    cin>>b;
    for(int i=0;i<b.size();i++){
        if(b[i]>='0'&&b[i]<='9') a[++k]=b[i]-'0';
    }
    sort(a+1,a+1+k);
    for(int i=k;i>=1;i--) cout<<a[i];
    return 0;
}

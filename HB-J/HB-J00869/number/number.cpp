#include<bits/stdc++.h>
using namespace std;
int n,k,a[1000005];
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++)if(s[i]<='9'&&s[i]>='0')a[k++]=s[i]-'0';
    sort(a,a+k);
    for(int i=k-1;i>=0;i--)printf("%d",a[i]);
    return 0;
}

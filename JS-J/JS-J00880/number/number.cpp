#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s,s2="";
    cin>>s;
    s=s+'*';
    int cn=0;
    for(int i=0;i<=s.size()-1;i++){
        if(s[i]>='0'&&s[i]<='9')a[++cn]=int(s[i]-'0');
    }
    sort(a+1,a+cn+1);
    for(int i=1;i<=cn;i++)s2=char(a[i]+'0')+s2;
    if(s2[0]!='0')cout<<s2<<endl;
    else cout<<0<<endl;
    return 0;
}

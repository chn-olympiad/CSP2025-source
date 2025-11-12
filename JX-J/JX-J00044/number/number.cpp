#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[15];
    for(int i=0;i<=15;i++) a[i]=0;
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            int l=s[i]-'0';
            a[l]++;
        }
    }
    for(int i=9;i>=0;i--){
        if(a[i]>0){
            for(;a[i]>0;a[i]--)cout<<i;
        }
    }
    return 0;
}

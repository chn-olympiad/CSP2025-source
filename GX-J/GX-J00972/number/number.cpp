#include<bits/stdc++.h>
using namespace std;
unsigned long long a[100000005];
string s;
bool cmp(unsigned long long x,unsigned long long y){
    return x>y;
}
int main(){
    cin>>s;
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    unsigned long long len=s.size();
    for(unsigned long long i=0;i<len;i++){
        a[i]=-1;
    }
    for(unsigned long long i=0;i<len;i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[i]=s[i]-'0';
        }
    }
    sort(a,a+s.size(),cmp);
    for(unsigned long long i=0;i<len;i++)
    {
        if(a[i]!=-1)
        cout<<a[i];
    }
    return 0;
}

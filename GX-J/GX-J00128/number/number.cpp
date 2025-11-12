#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000005],cnt;
int main() { 
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin>>s;
    int len=s.size();
    for(int i=0;i<len;i++) {
        if(s[i]-'0'==0) a[++cnt]=0;
        if(s[i]-'0'==1) a[++cnt]=1;
        if(s[i]-'0'==2) a[++cnt]=2;
        if(s[i]-'0'==3) a[++cnt]=3;
        if(s[i]-'0'==4) a[++cnt]=4;
        if(s[i]-'0'==5) a[++cnt]=5;
        if(s[i]-'0'==6) a[++cnt]=6;
        if(s[i]-'0'==7) a[++cnt]=7;
        if(s[i]-'0'==8) a[++cnt]=8;
        if(s[i]-'0'==9) a[++cnt]=9;
    } 
    sort(a+1,a+cnt+1);
    for(int i=cnt;i>=1;i--) cout<<a[i];
    return 0;
}

#include<bits/stdc++.h>
#define ll long long
#define u unsigned
using namespace std;
string s;
int a[1000005],tt;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[tt++]=s[i]-'0';
        }
    }
    sort(a,a+tt);
    for(int i=tt-1;i>=0;i--){
        printf("%d",a[i]);
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int cnt=0,cnt2=0;
    int len=s.length();
    for(int i=0;i<len;i++){
        char c=s[i];
        if(c>='a' && c<='z'){
            cnt2++;
        }
        else{
            a[++cnt]=s[i]-48;
        }
    }
    sort(a+1,a+cnt+1,greater<int>());
    for(int i=1;i<=cnt;i++){
        printf("%d",a[i]);
    }
    return 0;
}


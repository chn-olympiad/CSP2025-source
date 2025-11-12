#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
char s[1000002];
long long a[1000002],n=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(long long i=0;i<strlen(s);i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[i+1]=(s[i]-'0');
            n++;
        }
    }
    sort(a+1,a+n+1,cmp);
    for(long long i=1;i<=n;i++) cout<<a[i];
    return 0;
}

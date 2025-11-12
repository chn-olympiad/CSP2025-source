#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
string s;
LL a[1005],n=1;
bool cmp(const LL &x,const LL &y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(LL i=0;i<s.size();i++){
        if(isdigit(s[i])){
                a[n]=s[i]-'0';
                n++;
        }
    }
    sort(a+1,a+1+n,cmp);
    for(LL i=1;i<=n-1;i++) cout<<a[i];
    fclose(stdin);
    fclose(stdout);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s,ans;
    long long a[1000005],cnt=1,k=1;
    cin>>s;
    for(long long i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[cnt]=s[i]-'0';
            cnt++;
        }
    }
    sort(a+1,a+cnt);
    for(long long i=1;i<cnt;i++){
        ans=char(a[i]+'0')+ans;

    }
    cout<<ans;
    return 0;
}

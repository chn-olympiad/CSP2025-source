#include<bits/stdc++.h>
using namespace std;
char c;
string s,ans;
int num[1000005],sum,siz;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    siz=(s.size());
    for(int i=0;i<siz;i++){
        if(s[i]>=48 && s[i]<=57){
            sum++;
            num[sum]=(s[i]-48);
        }
    }
    sort(num+1,num+sum+1);
    while(sum>0){
        c=(num[sum]+48);
        ans=(ans+c);
        sum--;
    }
    cout<<ans;
    return 0;
}

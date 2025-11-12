#include <bits/stdc++.h>
using namespace std;
int t[1000005];
int main(){
   freopen("number.in","r",stdin);
   freopen("number.out","w",stdout);
    long long ans=0,maxx=0,sum=0;
    string s="";
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(s[i]>='0'&&s[i]<='9'){
            ans++;
            maxx=maxx*10+(s[i]-'0');
            t[i]=s[i]-'0';
        }
    }
    if(ans==1){
        printf("%lld",maxx);
        return 0;
    }
    for(int i=0;i<ans;i++){
        sum=0;
        next_permutation(t,t+ans);
        for(int j=0;j<ans;j++){
            sum=sum*10+t[j];
        }
        if(sum>maxx){
            long long num=sum;
        }
    }
    printf("%lld",num);
    return 0;
}

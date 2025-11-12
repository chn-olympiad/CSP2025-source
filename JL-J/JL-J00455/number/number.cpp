#include<bits/stdc++.h>
using namespace std;
string s;
long long len,p,times=0;
vector<long long>v;
long long cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    len=s.size();
    for(long long i=0;i<len;i++){
        if('0'<=s[i]&&s[i]<='9'){
            p=((int)(s[i]-'0'));
            v.push_back(p);
            times++;
        }
    }
    sort(v.begin(),v.end(),cmp);
    for(long long i=0;i<times;i++){
        cout<<v[i];
    }
    return 0;
}

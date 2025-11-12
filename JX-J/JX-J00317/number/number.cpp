#include<bits/stdc++.h>
using namespace std;
const long long N=1e6+10;
long long m[N];
bool cmp(long long x,long long y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    long long l=s.length();
    long long k=1;
    for(long long i=0;i<l;i++){
        if(s[i]>='0'&&s[i]<='9'){
            m[k]=s[i]-'0';
            k++;
        }
    }
    k-=1;
    sort(m+1,m+1+k,cmp);
    for(long long i=1;i<=k;i++){
        cout<<m[i];
    }
    return 0;
}

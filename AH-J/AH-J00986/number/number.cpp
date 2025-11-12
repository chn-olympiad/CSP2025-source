#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    long long m[1000005];
    long long n=0;
    long long l=s.size();
    for(long long i=0;i<=l-1;i++){
        if(s[i]>='0'&&s[i]<='9'){
			n++;
            m[n]=s[i]-48;
        }
    }
    sort(m+1,m+n+1);
    for(int i=n;i>=1;i--){
        cout<<m[i];
    }
    return 0;
}

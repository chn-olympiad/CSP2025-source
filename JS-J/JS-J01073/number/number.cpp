#include<bits/stdc++.h>
using namespace std;
int num[10],sum=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int len=s.size();
    for(int i=0;i<len;++i){
        if('0'<=s[i] && '9'>=s[i])
            num[s[i]-'0']++;
	}
    for(int i=9;i>=0;--i){
        for(;num[i]>0;num[i]--)
            cout<<i;
    }
    return 0;
}

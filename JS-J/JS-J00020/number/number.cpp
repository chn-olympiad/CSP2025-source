#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;
    long long s[10];
    memset(s,0,sizeof s);
    for(int i=0;i<a.size();i++){
        if(a[i]>='0'&&a[i]<='9'){
            s[(int)(a[i]-'0')]++;
        }
    }
    for(int i=9;i>=0;i--){
        for(long long j=1;j<=s[i];j++)cout<<i;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
string s;
long long i,a[1000100],he=0,cnt=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    long long len=s.size();
    for(i=0;i<len;i++){
        if(s[i]>='0'&&s[i]<='9'){
           a[cnt]=s[i]-'0';
           cnt++;
        }
    }
    sort(a,a+n);
    for(i=cnt-1;i>=0;i--){
        he=he*10+a[i];
    }
    cout<<he;
    return 0;
}

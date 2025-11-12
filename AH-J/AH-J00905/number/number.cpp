#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int len=s.size(),i,t=0;
    for(i=0;i<len;i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[i]=s[i]-'0';
            t++;
        }
    }
    sort(a+0,a+i);
    for(i=len-1;i>=0;i--){
        t--;
        if(t<0) break;
        cout<<a[i];
    }
    return 0;
}


#include<bits/stdc++.h>
using namespace std;
string s;
int a[10000000],l,cnt=0,flag0=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    l=s.size();
    for(int i=0;i<l;i++){
        if(s[i]>='0'&&s[i]<='9'){
            if(s[i]=='0'){
                flag0++;
            }
            cnt++;
            a[cnt]=s[i]-'0';
        }
    }
    if(flag0==cnt){
        cout<<0;
    }
    else{
        sort(a+1,a+1+cnt);
        for(int i=cnt;i>=1;i--){
            cout<<a[i];
        }
    }
    return 0;
}

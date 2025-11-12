#include<bits/stdc++.h>
using namespace std;
string s;
int len,a[1000005];

bool cmp(int x,int y){
    return x>y;
}

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    len=s.size();
    int cnt=0;
    for(int i=0; i<len; i++){
        if(s[i]>='0' && s[i]<='9'){
            cnt++;
            a[cnt]=s[i]-'0';
        }
    }
    sort(a+1,a+1+cnt,cmp);
   for(int i=1; i<=cnt; i++){
       if(a[1]==0){
           cout<<0;
           break;
       }
        cout<<a[i];
    }

    return 0;
}

#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000086],t;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);



    cin>>s;
    int len=s.size();
    for(int i=0;i<=len;i++){
        if(s[i]>='0'&&s[i]<='9'){
            t++;
            a[t]=s[i]-'0';
        }
    }
    sort(a,a+t+1);
    if(a[t]==0){
        cout<<'0';
        return 0;
    }
    for(int i=t;i>=1;i--){
        cout<<a[i];
    }

return 0;
}

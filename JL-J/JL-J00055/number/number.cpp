#include<bits/stdc++.h>
using namespace std;
long long a[1000005],cmp=1;
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<=s.size()-1;i++){
            if((s[i]-'0'==0)||(s[i]-'0'==1)||(s[i]-'0'==2)||(s[i]-'0'==3)||(s[i]-'0'==4)||(s[i]-'0'==5)||(s[i]-'0'==6)||(s[i]-'0'==7)||(s[i]-'0'==8)||(s[i]-'0'==9)){
                a[cmp]=s[i]-'0';
                cmp++;
            }
    }
    sort(a+1,a+1+cmp);
    for(int i=cmp;i>=2;i--){
        cout<<a[i];
    }
    return 0;
}

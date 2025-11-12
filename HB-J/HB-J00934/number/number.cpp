#include<bits/stdc++.h>
using namespace std;
int a[1010],mun=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string S;
    cin>>S;
    for(int i=0;i<S.length();i++){
        if(S[i]>='0' && S[i]<='9'){
            a[mun]=S[i]-'0';
            mun++;
        }
    }
    sort(a,a+mun);
    for(int i=mun-1;i>=0;i--){
        cout<<a[i];
    }

    return 0;
}

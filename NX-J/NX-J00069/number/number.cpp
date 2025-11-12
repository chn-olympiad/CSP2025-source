#include<bits/stdc++.h>
using namespace std;
bool sum(int a,int b){
    return b<a;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    string s;
    cin>>s;
    int a[1000005]={0};
    int ans=0;
    for(int i=0;i<s.size();i++){
        if(s[i]<='9' && s[i]>='0'){
            ans++;
            a[i]=s[i]-'0';

        }
    }
    sort(a,a+1000000,sum);

    for(int i=0;i<ans;i++){
        cout<<a[i];
    }


    return 0;
}

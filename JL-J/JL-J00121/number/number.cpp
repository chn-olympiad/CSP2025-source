#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int ans=0;
    string s,k;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            k+=s[i];
        }
    }
    int l=0,a[1000010]={};
    for(int i=0;i<k.size();i++){
        l++;
        a[i]=(k[i]-'0');
    }
    sort(a,a+l+1,cmp);
    for(int i=0;i<l;i++){
        ans=ans*10+a[i];
    }
    cout<<ans;
    return 0;
}

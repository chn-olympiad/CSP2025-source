#include<bits/stdc++.h>
using namespace std;
string s;int a[1100000];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;int n=0;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0' && s[i]<='9'){ 
            a[n]= int(s[i]-'0');
            n++;
        }
        //cout<<a[n]<<" ";
    }
    sort(a,a+n);
    int ans=0,sum=1;
    for(int i=0;i<n;i++){
        //cout<<a[i]<<" ";
        ans+=a[i]*sum;
        sum*=10;
    }
    cout<<ans;
    return 0;
}
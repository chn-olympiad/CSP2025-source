#include<bits/stdc++.h>
using namespace std;
int a[1001];
int ans=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            ans++;
            a[ans]=s[i]-48;
        }
    }
    //for(int i=1;i<=ans;i++)cout<<a[i]<<" ";
    sort(a+1,a+1+ans);
    if(a[ans]==0)cout<<"0";
    else
    for(int i=ans;i>=1;i--)cout<<a[i];
 return 0;
}

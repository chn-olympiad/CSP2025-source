#include<bits/stdc++.h>
using namespace std;
int cnt[10];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string n;
    cin>>n;
    for(int i=0;i<n.size();i++)
        if(n[i]>='0'&&n[i]<='9')
            cnt[n[i]-'0']++;
    int ans=0;
    for(int i=9;i>=0;i--)
        while(cnt[i]--)
            ans*=10,ans+=i;
    cout<<ans;
    return 0;
}

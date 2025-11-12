#include<bits/stdc++.h>
using namespace std;
int a[500010],s[500010];
int n,k,ans=0;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];s[i]=s[i-1]^a[i];
       // cout<<s[i]<<" ";
    }
    int qwq=0;
    for(int i=1;i<=n;i++){
        if(s[i]^qwq==k&&qwq!=-1){
            ans++;
            qwq=-1;
            //cout<<i<<endl;
        }
        if(qwq==-1&&(s[i]==0||s[i]==k)){
            qwq=s[i];
            //cout<<i<<" ";
        }
    }//cout<<endl;
    cout<<ans;

}
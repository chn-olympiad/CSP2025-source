#include<bits/stdc++.h>
using namespace std;
int a[1000050],s[10000050];
int max_ans;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        s[i]=(a[i]||a[i-1]);
    }
    for(int i=0,j=1;i<=n;i++){
        while(k>j){
          int ans=s[i]+s[j];
          max_ans=max(max_ans,ans);
        }
    }
    cout<<max_ans<<endl;
    return 0;
}

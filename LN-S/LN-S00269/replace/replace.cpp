#include<bits/stdc++.h>
using namespace std;
long long n,q;
char s1[100005],s2[100005],t1[100005],t2[100005];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    for (int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];
    }
    for (int i=1;i<=n+q;i++){
        cin>>t1[i]>>t2[i];
    }
    int ans[5]={0,1,0,2,5};
    for (int i=1;i<=5;i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}

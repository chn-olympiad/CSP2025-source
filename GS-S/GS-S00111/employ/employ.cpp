#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int t,n,ans=0;
    cin>>t>>n;
    string a;
    cin>>a;
    for(int i=0;i<a.size();i++){
        if(a[i]=='1') ans++;
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

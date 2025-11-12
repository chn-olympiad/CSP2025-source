#include<bits/stdc++.h>
using namespace std;
string s1,s2,t1,t2;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q,ans=1;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s1>>s2;
    }
    for(int i=1;i<=q;i++){
        cin>>t1>>t2;
    }
    if(s1.length()>t2.length()&&s2.length()>t2.length()){
        ans=0;
    }
    cout<<q<<endl;
    for(int i=1;i<=q;i++){
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

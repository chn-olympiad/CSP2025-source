#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    vector<int> v(n+1),sxor(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i];
        sxor[i]=sxor[i-1]^v[i];
    }
    set<int> st;
    int ans=0;
    for(int i=1;i<=n;i++){
        //for(auto j=st.begin();j!=st.end();j++)cout<<*j<<" ";cout<<"\n";
        if((st.find(k^sxor[i])!=st.end())||(sxor[i]^sxor[i-1])==k){
            ans++;
            st.clear();
        }
        else{
            st.insert(sxor[i-1]);
        }
    }
    cout<<ans;
    return 0;
}

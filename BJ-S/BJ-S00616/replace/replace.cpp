#include<bits/stdc++.h>
using namespace std;
typedef long long
ll;ll n,q;
string t[200005][2];
string w1,w2;
int pd(int a,int b){
string zs=w1;
for(int i=0;i<t[b][0].length();i++){
    if(zs[a+i]==t[b][0][i])
        zs[a+i]=t[b][1][i];
    else
        return 0;
}
if(zs==w2)
    return 1;
return 0;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>t[i][0]>>t[i][1];
    }
    while(q--){
        ll ans=0;
        cin>>w1>>w2;
        for(int i=0;i<w1.length();i++){
            for(int j=0;j<n;j++){
                if(w1[i]==t[j][0][0]){
                    ans+=pd(i,j);
                    //cout<<"!!"<<endl;
                    }
            }
        }
        cout<<ans<<endl;
    }

return 0;
}

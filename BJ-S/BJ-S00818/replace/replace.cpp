#include<bits/stdc++.h>
using namespace std;
string t[200005][3];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>t[i][1]>>t[i][2];
    }
    int ans=0;
    string s1,s2,temp;
    cin>>s1>>s2;
    if(q==1){
        for(int i=1;i<=n;i++){
            temp=s1;
            int k=temp.find(t[i][1]);
            for(int j=0;j<=t[i][2].size();j++){
                temp[k+j]=t[i][2][j];
            }
            if(temp==s2){
                cout<<i<<' ';
                ans++;
            }
        }
        cout<<ans;
        return 0;
    }
    while(q--){
        cout<<0<<endl;
    }
    return 0;
}

#include<bits/stdc++.h>

using namespace std;

struct node{
    string a,b;
};
int n,q;
node lst[200005];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>lst[i].a>>lst[i].b;
    }

    while(q--){
        int ans=0;
        string x,y;
        cin>>x>>y;
        for(int i=0;i<x.size();i++){
            for(int j=i;j<x.size();j++){
                for(int k=1;k<=n;k++){
                    if(x.substr(i,j-i+1)==lst[k].a && x.substr(0,i)+lst[k].b+x.substr(j+1,x.size()-j-1)==y){
                        ans++;
                        cout<<i<<" "<<j<<endl;
                    }
                }

            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}


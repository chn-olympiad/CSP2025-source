#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    string ch[n][2]={},qu[q][2]={};
    for(int i=0;i<n;i++){
        cin>>ch[i][0]>>ch[i][1];
        while(ch[i][0][0]==ch[i][1][0]){
            ch[i][0].erase(0,1);
            ch[i][1].erase(0,1);
        }
        while(ch[i][0][ch[i][0].size()-1]==ch[i][1][ch[i][1].size()-1]){
            ch[i][0].erase(ch[i][0].size()-1,ch[i][0].size());
            ch[i][1].erase(ch[i][1].size()-1,ch[i][1].size());
        }
    }
    for(int i=0;i<q;i++){
        cin>>qu[i][0]>>qu[i][1];
        while(qu[i][0][0]==qu[i][1][0]){
            qu[i][0].erase(0,1);
            qu[i][1].erase(0,1);
        }
        while(qu[i][0][qu[i][0].size()-1]==qu[i][1][qu[i][1].size()-1]){
            qu[i][0].erase(qu[i][0].size()-1,qu[i][0].size());
            qu[i][1].erase(qu[i][1].size()-1,qu[i][1].size());
        }
    }
    for(int i=0;i<q;i++){
        int ans=0;
        for(int j=0;j<n;j++){
            if(qu[i][0]==ch[j][0]&&qu[i][1]==ch[j][1]){
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

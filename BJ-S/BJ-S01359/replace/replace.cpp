#include<bits/stdc++.h>
using namespace std;
struct node{
    string x,y;
}a[100010];
string x,y;
int n,q;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>x>>y;
        a[i].x=x;
        a[i].y=y;
    }
    for(int i=1;i<=q;i++){
        int ans=0;
        cin>>x>>y;
        for(int j=0;j<x.size();j++){
            for(int len=1;len<=x.size()-j;len++){
                string s=x.substr(j,len),t=x.substr(0,max(0,j)),r=x.substr(j+len,x.size()-j-len);
                //cout<<t<<" "<<s<<" "<<r<<endl;
                for(int k=1;k<=n;k++){
                    if(s==a[k].x){//cout<<t+a[k].y+r<<endl;
                        if((t+a[k].y+r)==y) ans++;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

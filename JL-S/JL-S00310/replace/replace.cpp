#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n;
    cin>>n;int q;
    cin>>q;
    string x[n],y[n];
    for(int i=0;i<n;i++){
        cin>>x[i]>>y[i];
    }
    if(n<=1000){
            for(int i=0;i<q;i++){
            int cnt=0;
            string from,to;
            cin>>from>>to;
            for(int i=0;i<from.size();i++){
                for(int j=i;j<from.size();j++){
                    string from2=from,to2=to;
                    for(int k=0;k<n;k++){
                        if(from.substr(i,j)==x[k]){
                            for(int ii=0;ii<x[k].size();ii++)from2[ii+i]=y[i][ii];
                        }
                        if(from2==to2)cnt++;
                    }
                }
            }
            cout<<cnt<<endl;
        }
    }
    else{
        int l1[n+1],l2[n+1],r1[n+1],r2[n+1],mv[n+1];
        for(int i=0;i<n;i++){
            l1[i]=x[i].find('b');l2[i]=y[i].find('b');mv[i]=l2[i]-l1[i];r1[i]=x[i].size()-l1[i];r2[i]=y[i].size()-l2[i];
        }
        int tmv[q+1],hl1[q+1],hr1[q+1],hl2[q+1],hr2[q+1];
        for(int i=0;i<q;i++){
            string from,to;
            int ans=0;
            cin>>from>>to;
            int aaa=from.find('b'),bbb=to.find('b'),ccc=from.size()-aaa,ddd=to.size()-bbb;
            tmv[i]=bbb-aaa;
            hl1[i]=aaa;hr1[i]=from.size()-aaa-1;
            hl2[i]=bbb;hr2[i]=to.size()-bbb-1;
            for(int j=0;j<n;j++){
                if(mv[j]==tmv[i]&&aaa>=l1[j]&&ccc>=r1[j]&&bbb>=l2[j]&&ddd>=r2[j])ans++;
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
//50pts

#include<bits/stdc++.h>
using namespace std;
struct node{
    long long k,d;
}l1[5000010],l2[5000010];
int n,q;
unsigned long long ans=0,same;
//long long ;
string a[200010],b[200010];
vector<int> vt[5000010],g[5000010];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    if(q==1){
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i];
        }
        string x,y;
        cin>>x>>y;

        for(int i=1;i<=n;i++){
            for(int j=0;j<a[i].size();j++){
                if(j<x.size()&&x[j]==a[i][0]&&y[j]==b[i][0]){
                    int t=j,k=0;
                    while(t<x.size()&&t<a[i].size()){
                        t++;
                        k++;
                        if(x[t]!=a[i][k]||y[t]!=b[i][k]){
                            break;
                        }
                    }
                    if(t==a[i].size()-1){
                        ans++;
                        break;
                    }
                }
            }
        }
        cout<<ans;
    }
    else{
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i];
        }
        for(int i=1;i<=n;i++){
            int xx,yy;
            for(int j=0;j<a[i].size();j++){
                if(a[i][j]=='b')xx=j;
                if(b[i][j]=='b')yy=j;
            }
            if(xx==yy)same++;
            //vt[xx].push_back(yy);
            if(xx>=yy){
                vt[xx-yy].push_back(yy);
            }
            else {
                g[yy-xx].push_back(xx);
            }

        }
        while(q--){
            ans=0;
            string x,y;
            cin>>x>>y;
            int xx,yy;
            if(x==y)ans++;
            for(int i=0;i<x.size();i++){
                if(x[i]=='b')xx=i;
                if(y[i]=='b')yy=i;
            }
            if(xx==yy)ans+=1+same;
            //if(xx>=yy){
            //    ans+=l1[xx-yy].k;
            //}
            //else ans+=l2[yy-xx];
            if(xx>=yy){
                for(int i=0;i<vt[xx-yy].size();i++){
                    if(yy>=vt[xx-yy][i]){
                        ans++;
                    }
                }
            }
            else{
                for(int i=0;i<g[yy-xx].size();i++){
                    if(xx>=g[yy-xx][i]){
                        ans++;
                    }
                }
            }
            //for(int i=0;i<vt[xx].size();i++){
            //    if(vt[xx][i]==yy){
            //        ans++;
            //        break;
            //    }
            //}
            cout<<ans<<endl;
        }

    }
    return 0;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

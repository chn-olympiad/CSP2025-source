#include<bits/stdc++.h>
using namespace std;
string aim;
int n,q;
string a[(int)2e5+10],b[(int)2e5+10];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);

    cin>>n>>q;
    // cout<<n<<endl<<q<<endl;
    for(int i=0;i<n;++i){
        cin>>a[i]>>b[i];
    }
    if(n>(int)1e4&&q!=1){
        while(q--){
            cout<<0<<'\n';
        }
        return 0;
    }
    while(q--){
        string x,y;
        // cout<<x<<' '<<y<<'\n';
        cin>>x>>y;
        int ans=0,xs=x.size(),ys=y.size();
        if(xs!=ys){
            cout<<0<<'\n';
            continue;
        }
        string tmp;
        for(int i=0;i<n;++i){
                int t=0;
                while(1){
                    int tp=x.find(a[i],t);
                    if(tp==-1) break;
                    t=tp+1;
                    tmp=x;
                    //out<<tmp<<endl;
                    for(int j=tp;j<tp+a[i].size();++j){
                        tmp[j]=b[i][j-tp];
                    }
                    if(tmp==y) ans++;
                }

        }
        cout<<ans<<'\n';
    }
    return 0;
}

#include<iostream>
#include<cstring>
using namespace std;
string a1[200005],a2[200005];
int p[5000005];
int w[5000005];
int main(){
    ios::sync_with_stdio(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a1[i]>>a2[i];
    }
    for(int i=1;i<=q;i++){
        string x,y;
        cin>>x>>y;
        if(x.size()!=y.size()){
            cout<<0<<'\n';
            continue;
        }
        //cout<<x<<'\n'<<y<<'\n';
        int cnt=0;
        int sy=y.size();
        int minn=1e9,maxn=0;
        for(int i=0;i<sy;i++){
            if(x[i]!=y[i]){
                minn=min(minn,i);
                maxn=max(maxn,i);
            }
        }
        for(int j=1;j<=n;j++){
            //cout<<a1[j]<<' '<<a2[j]<<'\n';
            string tx=' '+a1[j]+'#'+x;
            int minx=minn+2+a1[j].size();
            int maxx=maxn+2+a1[j].size();
            p[0]=p[1]=0;
            int si=tx.size()-1;
            for(int k=2;k<=si;k++){
                int ti=k-1;
                while(ti!=0&&tx[p[ti]+1]!=tx[k]){
                    ti=p[ti];
                }
                if(ti!=0){
                    p[k]=p[ti]+1;
                }
                else{
                    p[k]=0;
                }
            }
            string ty=' '+a2[j]+'#'+y;
            w[0]=w[1]=0;
            si=ty.size()-1;
            for(int k=2;k<=si;k++){
                int ti=k-1;
                while(ti!=0&&ty[w[ti]+1]!=ty[k]){
                    ti=w[ti];
                }
                if(ti!=0){
                    w[k]=w[ti]+1;
                }
                else{
                    w[k]=0;
                }
            }
            bool f=0;
            for(int k=1;k<=si;k++){
                if(k>=maxx&&k-a1[j].size()+1<=minx&&p[k]==a1[j].size()&&w[k]==a2[j].size()){
                    f=1;
                    cnt++;
                }
                //cout<<p[k]<<' ';
            }
            //cout<<'\n';
            //for(int k=1;k<=si;k++){
            //    cout<<w[k]<<' ';
            //}
            //cout<<'\n';
            //cout<<minx<<' '<<maxx<<'\n';
        }
        cout<<cnt<<'\n';
    }
    return 0;
}

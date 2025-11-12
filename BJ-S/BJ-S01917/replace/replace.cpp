#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

const int N=5000005,V=30;
const int P=11451497,MOD=1000000007;

int fpow[N];

string s[N][2],t[2];
int phsh[N][2],sp[N];

int hsh[2][N];
void hashinit(int id,string& s){
    int n=s.size()-1;
    for(int i=1;i<=n;++i){
        hsh[id][i]=(1ll*hsh[id][i-1]*P+s[i])%MOD;
    }
}
int get(int id,int l,int r){
    return (hsh[id][r]-1ll*fpow[r-l+1]*hsh[id][l-1]%MOD+MOD)%MOD;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    fpow[0]=1;
    for(int i=1;i<N;++i){
        fpow[i]=1ll*fpow[i-1]*P%MOD;
    }

    int n,q;
    cin>>n>>q;
    bool flag=true;
    for(int i=1;i<=n;++i){
        cin>>s[i][0]>>s[i][1];
        s[i][0]='@'+s[i][0];
        s[i][1]='@'+s[i][1];
        phsh[i][0]=phsh[i][1]=0;
        int acnt=0,bcnt=0;
        for(int j=1;j<s[i][1].size();++j){
            phsh[i][0]=(1ll*phsh[i][0]*P+s[i][0][j])%MOD;
            phsh[i][1]=(1ll*phsh[i][1]*P+s[i][1][j])%MOD;
            if(s[i][0][j]=='a') ++acnt;
            if(s[i][0][j]=='b'){
                ++bcnt;
                sp[i]=j;
            }
        }if(acnt+bcnt==s[i][0].size()-1 && bcnt==1){
            ;
        }else{
            //cout<<i<<' '<<acnt<<' '<<bcnt<<' '<<s[i][0].size()<<endl;
            flag=false;
        }
    }//cout<<flag<<endl;

    while(q--){
        cin>>t[0]>>t[1];
        int m=t[0].size();
        t[0]='@'+t[0];
        t[1]='@'+t[1];
        hashinit(0,t[0]);
        hashinit(1,t[1]);
        int bl=1,br=m,bp;
        for(int i=1;i<=m;++i){
            if(get(0,1,i)==get(1,1,i)){
                bl=i+1;
            }if(get(0,i,m)==get(1,i,m)){
                br=min(br,i-1);
            }
            if(t[0][i]=='b') bp=i;
        }
        //cout<<"---> "<<bl<<' '<<br<<'\n';
        int ans=0;
        for(int j=1;j<=n;++j){
            if(!flag){
                for(int i=1;i<=bl;++i){
                    if(i+s[j][0].size()-2>=br && i+s[j][0].size()-2<=m){
                        ans+=(get(0,i,i+s[j][0].size()-2)==phsh[j][0] &&
                            get(1,i,i+s[j][1].size()-2)==phsh[j][1]);
                        //cout<<j<<' '<<i<<' '<<i+s[j][0].size()-2
                        //    <<get(0,i,i+s[j][0].size()-2)<<' '<<phsh[j][0]<<' '
                        //    <<get(1,i,i+s[j][1].size()-2)<<' '<<phsh[j][1]<<'\n';
                    }
                }
            }else{
                int i=bp-sp[j]+1;
                if(i<=bl && i+s[j][0].size()-2>=br && i+s[j][0].size()-2<=m){
                    ans+=(get(0,i,i+s[j][0].size()-2)==phsh[j][0] &&
                        get(1,i,i+s[j][1].size()-2)==phsh[j][1]);
                    //cout<<j<<' '<<i<<' '<<i+s[j][0].size()-2
                    //    <<get(0,i,i+s[j][0].size()-2)<<' '<<phsh[j][0]<<' '
                    //    <<get(1,i,i+s[j][1].size()-2)<<' '<<phsh[j][1]<<'\n';
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}



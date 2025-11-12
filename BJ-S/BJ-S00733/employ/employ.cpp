#include<bits/stdc++.h>
using namespace std;
namespace compile{
    void begin(){
        #ifdef DOWN
            FILE *fp_in=freopen("employ3.in","r",stdin);
            FILE *fp_out=freopen("out","w",stdout);
        #else
            FILE *fp_in=freopen("employ.in","r",stdin);
            FILE *fp_out=freopen("employ.out","w",stdout);
        #endif
        ios::sync_with_stdio(0);
        return ;
    }
    void end(){
        #ifdef TIME
            cerr<<"程序运行时间:"<<1.0*clock()/CLOCKS_PER_SEC<<"秒"<<endl;
        #endif
        return ;
    }
}
#define ll long long
const int N=505;
int n,m,cnt,ans;
string s;
int c[N];
int id[N];
void init(){
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++){
        cin>>c[i];
        id[i]=i;
    }
    do{
        cnt=0;
        for(int i=1;i<=n;i++){
            if(s[i-1]=='0' or cnt>=c[id[i]])cnt++;
        }
        ans+=(n-cnt>=m);
    }while(next_permutation(id+1,id+n+1));
    cout<<ans<<endl;
    return ;
}
void work(){

    return ;
}
signed main(){
    compile::begin();
    init();
    work();
    compile::end();
    return 0;
}

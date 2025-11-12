#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct sss{
    string now="";
    string _to="";
    string aft="";
    string bef="";
    void g(string _a,string _b){
        int af=0;
        int be=min(_a.size(),_b.size());
        while(_a[af]==_b[af]&&af<=be-1) af++;
        while(_a[be]==_b[be]&&be>=1) be--;
        aft=_a.substr(0,af);
        bef=_a.substr(be,min(_a.size(),_b.size())-be-1);
        now=_a.substr(af,be-af+1);
        _to=_b.substr(af,be-af+1);
    }
    int finda(string _a){
        int x=aft.size()-1;
        int y=_a.size()-1;
        if(x>y)
            return -1;
        for(;x>=0;y--,x--){
            if(aft[x]!=_a[y])
                return -1;
        }
        return 1;
    }
    int findb(string _a){
        int x=0;
        int y=0;
        if(bef.size()>_a.size())
            return -1;
        for(;x<bef.size();y++,x++){
            if(bef[x]!=_a[y])
                return -1;
        }
        return 1;
    }
};
sss qwe,_aft,_bef,a;
vector<sss> S[300];//now aft bef
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        string _a,_b;
        cin>>_a>>_b;
        a.g(_a,_b);
        S[a.now[0]].push_back(a);
        //cout<<i<<endl;
    }
    for(int i=1;i<=k;i++){
        string _a,_b;
        cin>>_a>>_b;
        if(_a.size()!=_b.size()){
            cout<<0<<endl;
            continue;
        }
        qwe.g(_a,_b);
        if(S[qwe.now[0]].size()==0){
            cout<<0<<endl;
            continue;
        }

        int ans=0;
        //cout<<qwe.aft<<' '<<qwe.now<<' '<<qwe.bef<<endl;
        for(int i=0;i<S[qwe.now[0]].size();i++){
            //cout<<S[qwe.now[0]][i].aft+S[qwe.now[0]][i].now+S[qwe.now[0]][i].bef<<endl;
            if(S[qwe.now[0]][i].now==qwe.now&&S[qwe.now[0]][i]._to==qwe._to
               &&S[qwe.now[0]][i].finda(qwe.aft)!=-1
               &&S[qwe.now[0]][i].findb(qwe.bef)!=-1
               ){
                ans++;
                //cout<<S[qwe.now[0]][i].aft+S[qwe.now[0]][i].now+S[qwe.now[0]][i].bef<<endl;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
//184

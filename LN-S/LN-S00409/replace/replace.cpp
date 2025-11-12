#include <bits/stdc++.h>
using namespace std;
namespace Light_Tea{
    void Main();
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);

    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    Light_Tea::Main();
    return 0;
}
namespace Light_Tea{
    using i64 = long long;
    #define ALL(v) begin(v), end(v)

    constexpr int kN=2e5+5, kL=5e6+5;

    int n,q;
    string s[3][kN],t1,t2;

    struct ACAM{
        int son[kL][26],fail[kL],rec[kL];
        vector<int> vec[kL];
        int node;

        void insert(string &s,int id){
            int u=0;
            for(auto &c:s){
                if(!son[u][c-'a']) son[u][c-'a']=++node;
                u=son[u][c-'a'];
            }
            vec[u].push_back(id);
        }

        void Build(){
            for(int i=1; i<=node; i++) sort(ALL(vec[i]));

            queue<int> Q;
            for(int i=0; i<26; i++) if(son[0][i]){
                Q.push(son[0][i]);
            }

            while(!Q.empty()){
                int u=Q.front(); Q.pop();
                for(int i=0; i<26; i++){
                    if(!son[u][i]){
                        son[u][i]=son[fail[u]][i];
                    }else{
                        fail[son[u][i]]=son[fail[u]][i];
                        Q.push(son[u][i]);
                    }
                }
            }

            for(int i=0; i<=node; i++) rec[i]=-1;
        }

        int GoNxt(int u,int c){
            return son[u][c];
        }
    }A1,A2;

    void Up(int &p,ACAM &A){
        if(A.rec[p]!=-1) return p=A.rec[p], void();
        auto &t=A.rec[p];
        while(p!=0&&A.vec[p].size()==0){
            p=A.fail[p];
            if(A.rec[p]!=-1) p=A.rec[p];
        }
        t=p;
    }

    int Calc(int p1,int p2,int lim){
        Up(p1,A1), Up(p2,A2);
        if(p1==0||p2==0) return 0;
        int sz1=s[1][A1.vec[p1][0]].length(), sz2=s[2][A2.vec[p2][0]].length();
        if(sz1<lim||sz2<lim) return 0;
        if(sz1>sz2){
            p1=A1.fail[p1]; return Calc(p1,p2,lim);
        }else if(sz2>sz1){
            p2=A2.fail[p2]; return Calc(p1,p2,lim);
        }

        int c1=0, c2=0, o1=A1.vec[p1].size(), o2=A2.vec[p2].size(), res=0;
        while(c1<o1&&c2<o2){
            int x1=A1.vec[p1][c1], x2=A2.vec[p2][c2];
            if(x1==x2) res++;
            if(x1<=x2) c1++;
            else c2++;
        }

        p1=A1.fail[p1], p2=A2.fail[p2];
        return res+Calc(p1,p2,lim);
    }

    void Query(int n,int l,int r){
        int p1=0, p2=0, ans=0;
        for(int i=0; i<n; i++){
            p1=A1.GoNxt(p1,t1[i]-'a');
            p2=A2.GoNxt(p2,t2[i]-'a');

            if(i>=r){
                ans+=Calc(p1,p2,i-l+1);
            }
        }
        cout << ans << '\n';
    }

    void Main(){
        cin >> n >> q;
        for(int i=1; i<=n; i++){
            cin >> s[1][i] >> s[2][i];
            A1.insert(s[1][i],i), A2.insert(s[2][i],i);
        }

        A1.Build(), A2.Build();
        
        while(q--){
            cin >> t1 >> t2;
            int n=t1.length(), l=0, r=0;
            for(int i=0; i<n; i++){
                if(t1[i]!=t2[i]){l=i; break;}
            }
            for(int i=n-1; i>=0; i--){
                if(t1[i]!=t2[i]){r=i; break;}
            }

            Query(n,l,r);
        }
    }
}
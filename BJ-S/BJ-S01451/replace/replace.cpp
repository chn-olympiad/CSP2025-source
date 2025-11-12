#include <bits/stdc++.h>
using namespace std;
const int maxn=1007;
const int maxl=2007;

int nxt[maxn][maxl][2];
string key[maxn],goal[maxn];

void pre(int ind,int which,string a){
    nxt[ind][0][which] = 0;
    for(int i=1;i<a.length();i++){
        int h=i-1;
        while(h != 0  &&  a[nxt[ind][h][which]] != a[i]) h=nxt[ind][h-1][which];
        if(a[nxt[ind][h][which]] == a[i])
            nxt[ind][i][which] = nxt[ind][h][which]+1;
        else
            nxt[ind][i][which] = 0;
    }
    return;
}

vector<int> res_check;
void check(int ind,int which,string a,string b){
    res_check.clear();
    int inda=0,indb=0;
    while(true){
        if(inda == a.length()){
            res_check.push_back(indb);
            indb += inda-nxt[ind][inda-1][which];
            inda = 0;
            continue;
        }
        if(inda+indb >= b.length())
            break;
        if(b[inda+indb] == a[inda]){
            inda++;
        }
        else{
            if(inda != 0)
                indb += inda-nxt[ind][inda-1][which];
            else
                indb++;
            inda = 0;
        }
    }
}

int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>key[i]>>goal[i];
        pre(i,0,key[i]);
        pre(i,1,goal[i]);
    }
    for(int Q=1;Q<=q;Q++){
        int ans=0;
        string a,b;
        cin>>a>>b;
        int start,stop;
        for(int i=0;i<min(a.length(),b.length());i++){
            if(a[i] != b[i]){
                start = i;
                break;
            }
        }
        for(int i=1;i<=min(a.length(),b.length());i++){
            if(a[a.length()-i] != b[b.length()-i]){
                stop = i;
                break;
            }
        }
        for(int i=1;i<=n;i++){
            if(key[i].length() > a.length()  ||  goal[i].length() > b.length())
                continue;
            if(key[i].length()-goal[i].length() != a.length()-b.length())
                continue;
            vector<int> da,db;
            check(i,0,key[i],a);
            da = res_check;
            check(i,1,goal[i],b);
            db = res_check;
            int inda=0,indb=0;
            while(inda < da.size()  &&  indb < db.size()){
                //cout<<i<<" "<<1<<endl;
                if(da[inda] > db[indb]){
                    indb++;
                    continue;
                }
                if(da[inda] < db[indb]){
                    inda++;
                    continue;
                }
                if(da[inda] > start  ||  db[indb] > start)
                    break;
                if(da[inda] == db[indb]){
                    if(da[inda]+key[i].length()-1 >= a.length()-stop  &&  db[indb]+goal[i].length()-1 >= b.length()-stop){
                        ans++;
                        //cout<<"   "<<i<<endl;
                    }
                    inda++, indb++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

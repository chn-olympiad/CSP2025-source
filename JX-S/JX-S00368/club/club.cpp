#include<bits/stdc++.h>
using namespace std;
struct node{
    int a,b,c;
    int maxs,mids,mins;
    int maxi,midi,mini;
    int x,id;
    int st,en;
    bool operator<(const node &T)const{
        return st-en>T.st-T.en;
        //return maxi>T.maxi;
    }
}p[100005];
priority_queue<node,vector<node> >q[4][4];
int n;
long long cnt;
bool cmp(node a,node b){
    return a.maxs>b.maxs;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        cnt =0;
        cin>>n;
        memset(p,0,sizeof (p));
        for (int i=1;i<=n;++i){
            cin>>p[i].a>>p[i].b>>p[i].c;
            p[i].maxs=max(max(p[i].a,p[i].b),p[i].c);
            p[i].mins=min(min(p[i].a,p[i].b),p[i].c);
            p[i].mids=p[i].a+p[i].b+p[i].c-p[i].maxs-p[i].mins;
            if (p[i].maxs==p[i].a){
                if (p[i].mids==p[i].b)p[i].maxi=1,p[i].midi=2,p[i].mini=3;
                else p[i].maxi=1,p[i].midi=3,p[i].mini=2;
            }
            else if (p[i].maxs==p[i].b){
                if (p[i].mids==p[i].a)p[i].maxi=2,p[i].midi=1,p[i].mini=3;
                else p[i].maxi=2,p[i].midi=3,p[i].mini=1;
            }
            else {
                if (p[i].mids==p[i].b)p[i].maxi=3,p[i].midi=2,p[i].mini=1;
                else p[i].maxi=3,p[i].midi=1,p[i].mini=2;
            }



        }
        sort(p+1,p+n+1,cmp);
        for (int i=1;i<=n;++i){
            if(q[p[i].maxi][p[i].midi].size()+q[p[i].maxi][p[i].mini].size()+q[p[i].maxi][0].size()+1<=n/2){
                q[p[i].maxi][p[i].midi].push({p[i].a,p[i].b,p[i].c,p[i].maxs,p[i].mids,p[i].mins,p[i].maxi,p[i].midi,p[i].mini,p[i].maxs,i,p[i].maxi,p[i].midi});
            }
            else{
                if (q[p[i].maxi][p[i].midi].top().st-q[p[i].maxi][p[i].midi].top().en>p[i].maxs-p[i].mids){
                    if (q[p[i].midi][p[i].maxi].size()+q[p[i].midi][p[i].mini].size()+q[p[i].midi][0].size()+1<=n/2){
                        q[p[i].midi][p[i].mini].push({p[i].a,p[i].b,p[i].c,p[i].maxs,p[i].mids,p[i].mins,p[i].maxi,p[i].midi,p[i].mini,p[i].mids,i,p[i].midi,p[i].mini});
                    }
                    else {
                        if (q[p[i].midi][p[i].mini].top().st-q[p[i].midi][p[i].mini].top().en>p[i].midi-p[i].mini){
                            q[p[i].mini][0].push({p[i].a,p[i].b,p[i].c,p[i].maxs,p[i].mids,p[i].mins,p[i].maxi,p[i].midi,p[i].mini,p[i].mins,i,p[i].mini,0});
                        }
                        else {
                            node o=q[p[i].midi][p[i].mini].top();
                            q[p[i].midi][p[i].mini].pop();
                            q[p[i].midi][p[i].mini].push({p[i].a,p[i].b,p[i].c,p[i].maxs,p[i].mids,p[i].mins,p[i].maxi,p[i].midi,p[i].mini,p[i].mids,i,p[i].midi,p[i].mini});
                            q[o.en][0].push({o.a,o.b,o.c,o.maxs,o.mids,o.mins,o.maxi,o.midi,o.mini,o.mins,o.id,o.en,0});

                        }
                    }
                }
                else {
                    node f=q[p[i].maxi][p[i].midi].top();
                    if (q[f.midi][f.maxi].size()+q[f.midi][f.mini].size()+q[f.midi][0].size()+1<=n/2){
                        q[p[i].maxi][p[i].midi].pop();
                        q[p[i].maxi][p[i].midi].push({p[i].a,p[i].b,p[i].c,p[i].maxs,p[i].mids,p[i].mins,p[i].maxi,p[i].midi,p[i].mini,p[i].maxs,i,p[i].maxi,p[i].midi});
                        q[f.en][f.mini].push({f.a,f.b,f.c,f.maxs,f.mids,f.mins,f.maxi,f.midi,f.mini,f.mids,f.id,f.en,f.mini});
                    }
                    else {
                        if (q[f.midi][f.mini].top().st-q[f.midi][f.mini].top().en>f.midi-f.mini){
                            q[p[i].maxi][p[i].midi].pop();
                            q[p[i].maxi][p[i].midi].push({p[i].a,p[i].b,p[i].c,p[i].maxs,p[i].mids,p[i].mins,p[i].maxi,p[i].midi,p[i].mini,p[i].maxs,i,p[i].maxi,p[i].midi});
                            q[f.mini][0].push({f.a,f.b,f.c,f.maxs,f.mids,f.mins,f.maxi,f.midi,f.mini,f.mins,f.id,f.mini,0});
                        }
                        else {
                            node o=q[f.midi][f.mini].top();
                            q[f.midi][f.mini].pop();
                            q[p[i].maxi][p[i].midi].pop();
                            q[f.midi][f.mini].push({f.a,f.b,f.c,f.maxs,f.mids,f.mins,f.maxi,f.midi,f.mini,f.mins,f.id,f.midi,f.mini});
                            q[o.en][0].push({o.a,o.b,o.c,o.maxs,o.mids,o.mins,o.maxi,o.midi,o.mini,o.mins,o.id,o.en,0});
                            q[p[i].maxi][p[i].midi].push({p[i].a,p[i].b,p[i].c,p[i].maxs,p[i].mids,p[i].mins,p[i].maxi,p[i].midi,p[i].mini,p[i].maxs,i,p[i].maxi,p[i].midi});

                        }
                    }
                }
            }

        }
        for (int i=0;i<=3;++i){
            for (int j=0;j<=3;++j){
                while(!q[i][j].empty()){
                    cnt +=q[i][j].top().x;
                    cout<<q[i][j].top().id<<" "<<i<<" "<<j<<" "<<q[i][j].top().x<<endl;
                    q[i][j].pop();
                }
            }
        }
        cout<<cnt<<'\n';
    }

    return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,M=5e6+5;
int n,q,l1,l2,sum[M],cnt;
long long res[N];
string s[N][2],t[N][2];
int lowbit(int x){
    return x&(-x);
}
void update(int x,int w){
    while(x<=l2) sum[x]+=w,x+=lowbit(x);
}
int query(int x){
    int ans=0;
    while(x) ans+=sum[x],x-=lowbit(x);
    return ans;
}
struct interval{
    int d,o,x,y,idx;
}v[N];
bool cmp(interval a,interval b){
    if(a.d!=b.d) return a.d<b.d;
    if(a.o!=b.o) return a.o<b.o;
    if(a.x!=b.x) return a.x<b.x;
    return a.y<b.y;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s[i][0]>>s[i][1];
        l1+=(int)s[i][0].length()+(int)s[i][1].length();
    }
    for(int i=1;i<=n;i++){
        cin>>t[i][0]>>t[i][1];
        l2+=(int)t[i][0].length()+(int)t[i][1].length();
    }
    if(l1<=2000&&l2<=2000){
        cout<<"wait";
    }
    else{
        cnt=n;
        for(int i=1;i<=n;i++){
            int pa,pb;
            int len=s[i][0].length();
            for(int j=0;j<len;j++){
                if(s[i][0][j]=='b'){
                    pa=j+1;
                    break;
                }
            }
            for(int j=0;j<len;j++){
                if(s[i][1][j]=='b'){
                    pb=j+1;
                    break;
                }
            }
            v[i].d=pa-pb,v[i].o=0,v[i].x=pa,v[i].y=len-pb+1,v[i].idx=i;
        }
        for(int i=1;i<=q;i++){
            int pa,pb;
            int len=t[i][0].length(),len1=t[i][1].length();
            if(len!=len1) continue;
            cnt++;
            for(int j=0;j<len;j++){
                if(t[i][0][j]=='b'){
                    pa=j+1;
                    break;
                }
            }
            for(int j=0;j<len;j++){
                if(t[i][1][j]=='b'){
                    pb=j+1;
                    break;
                }
            }
            v[cnt].d=pa-pb,v[cnt].o=1,v[cnt].x=pa,v[cnt].y=len-pb+1,v[cnt].idx=i;
        }
        sort(v+1,v+cnt+1,cmp);
        v[0].d=-1e9;
        for(int i=1,l=1;i<=cnt;i++){
            if(v[i].d!=v[i-1].d){
                for(int j=l;j<i;j++)
                    if(!v[j].o) update(v[j].y,-1);
                l=i;
            }
            if(!v[i].o) update(v[i].y,1);
            else res[v[i].idx]=query(v[i].y);
        }
        for(int i=1;i<=q;i++) cout<<res[i]<<"\n";
    }
    return 0;
}
#include<iostream>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;
int n;long long k,num[500010],x[500010],f[500010],la[500010],ans,cnt,mxr,cntqe;
struct lines{long long l,r;}ln[500100];
queue<int>qe[500010];map<long long,int>toid;
bool cmp(lines x,lines y){return x.r<y.r;}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>num[i];
        x[i]=num[i]^x[i-1];
        f[i]=x[i]^k;
    }
    /*cout<<'\n';
    for(int i=0;i<=n;i++)cout<<x[i]<<' ';
    cout<<'\n';
    for(int i=0;i<=n;i++)cout<<f[i]<<' ';
    cout<<'\n';*/

    for(int i=1;i<=n;i++){
        if(!toid[f[i]])toid[f[i]]=++cntqe;
        qe[toid[f[i]]].push(i);
    }
   // cout<<0x3f3f3f3f<<'\n';
    for(int i=0;i<=n;i++){
        if(!toid.count(x[i]))la[i]=0x3f3f3f3f;
        else{
            int idnow=toid[x[i]];
            while(qe[idnow].size()&&qe[idnow].front()<=i)qe[idnow].pop();
            if(!qe[idnow].size())la[i]=0x3f3f3f3f;
            else la[i]=qe[idnow].front();
        }
    }

    /*for(int i=0;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(f[j]==x[i]){la[i]=j;break;}
        }
        if(!la[i])la[i]=0x3f3f3f3f;
    }*/



    //for(int i=0;i<=n;i++)cout<<i+1<<' '<<la[i]<<'\n';
    for(int i=0;i<=n;i++)if(la[i]!=0x3f3f3f3f)ln[++cnt]={i+1,la[i]};
    sort(ln+1,ln+cnt+1,cmp);
    for(int i=1;i<=cnt;i++){
        if(ln[i].l>mxr){
            mxr=ln[i].r;
            ++ans;
        }
    }
    cout<<ans;
    return 0;
}

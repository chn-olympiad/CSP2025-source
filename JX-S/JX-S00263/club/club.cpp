#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll t,n;
int siz[5];
struct node{
    ll vall;
    ll chaa;
}aa[100005];
struct Node{
    ll cha;
    ll num;
    bool operator <(const Node &other)const{
        return cha>other.cha;
    }
};
priority_queue<Node> q;
int read(){
    char ch=getchar();
    int a=ch-'0';
    while(ch=getchar(),ch>='0'&&ch<='9'){
        a=a*10+ch-'0';
    }
    return a;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cout.tie(0);
    t=read();
    while(t--){
        while(q.size()){
        q.pop();
        }
        n=read();
        ll ans=0;
        memset(siz,0,sizeof(siz));
        for(int i=1;i<=n;i++){
            ll a11,a22,a33;
            a11=read();
            a22=read();
            a33=read();
            aa[i].vall=max(max(a11,a22),a33);
            ans+=aa[i].vall;
            if(a33==aa[i].vall){
                aa[i].chaa=a33-max(a11,a22);
                siz[3]++;
                q.push({aa[i].chaa,3});
            }
            else if(a22==aa[i].vall){
                aa[i].chaa=a22-max(a33,a11);
                siz[2]++;
                q.push({aa[i].chaa,2});
            }
            else{
                aa[i].chaa=a11-max(a33,a22);
                siz[1]++;
                q.push({aa[i].chaa,1});
            }
        }
        int op=(siz[1]>n/2)+2*(siz[2]>n/2)+3*(siz[3]>n/2);
        if(op==0){
            cout<<ans<<endl;

            continue;
        }
        while(q.size()){
            Node f=q.top();
            q.pop();
            if(f.num!=op)continue;
            ans-=f.cha;
            siz[op]--;
            if(siz[op]<=n/2)break;
        }
        cout<<ans<<endl;
    }
    return 0;
}


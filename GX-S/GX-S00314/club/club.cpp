#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
struct Node{
    int a,b,c;
};


int t,n,ca,cb,cc;
Node na[N],nb[N],nc[N],nd[N];
vector<int>del;
int mx,le,ri;
ll ans;


bool cmp(int x,int y){
    return x>y;
}

void sol(Node *tmp, int tp){
    int ot[5];
    for(int i=1;i<=tp;i++){
        ot[1]=tmp[i].a, ot[2]=tmp[i].b, ot[3]=tmp[i].c;
        del.push_back(max(ot[le],ot[ri])-ot[mx]);
    }
    sort(del.begin(),del.end(),cmp);

    int i=0;
    while(tp>n/2){
        ans+=del[i];
        tp--;i++;
    }
    printf("%lld\n",ans);
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        //clear
        ans=ca=cb=cc=0;
        del.clear();

        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d%d%d",&nd[i].a,&nd[i].b,&nd[i].c);
        for(int i=1;i<=n;i++){
            if(nd[i].a>=nd[i].b&&nd[i].a>=nd[i].c)na[++ca]=nd[i], ans+=nd[i].a;
            else if(nd[i].b>=nd[i].a&&nd[i].b>=nd[i].c)nb[++cb]=nd[i], ans+=nd[i].b;
            else nc[++cc]=nd[i], ans+=nd[i].c;
        }
        if(ca>n/2){mx=1,le=2,ri=3; sol(na,ca);}
        else if(cb>n/2){mx=2,le=1,ri=3; sol(nb,cb);}
        else if(cc>n/2){mx=3,le=1,ri=2; sol(nc,cc);}
        else printf("%lld\n",ans);
    }
    return 0;
}

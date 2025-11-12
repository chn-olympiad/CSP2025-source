#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=1e4+5;
const int maxm=1e7+5;

struct Node{
    ll v,w;
    Node *prev,*next;
};

struct Data{
    ll u,v,w;
    bool operator<(const Data other)const{
        return w<other.w;
    }
};

// class Linklist{
//     public:
//     int len;
//     Node *head,*tail;
//     Linklist(){
//         head=new Node();
//         tail=new Node();
//         head->next=tail;
//         tail->prev=head;
//     }
// };

int cnt;
int n,m,k;
Data a[maxm];
bool v[maxn];

void init(){
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>a[i].u>>a[i].v>>a[i].w;
    }
    cnt=m;
    ll c;
    ll w[maxn];
    for(int i=1;i<=k;i++){
        cin>>c;
        for(int j=1;j<=n;j++){
            cin>>w[j];
        }
        for(int j=1;j<=n;j++){
            for(int k=j+1;k<=n;k++){
                a[++cnt].u=j;
                a[cnt].v=k;
                a[cnt].w=c+w[j]+w[k];
            }
        }
    }
}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    init();
    sort(a+1,a+cnt+1);
    int emp=n;
    int i=1;
    int ans=0;
    while(emp!=0){
        if(v[a[i].u]==0 || v[a[i].v]==0){
            if(v[a[i].u]==0) emp--;
            if(v[a[i].v]==0) emp--;
            v[a[i].u]=1;
            v[a[i].v]=1;
            ans+=a[i].w;
            i++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
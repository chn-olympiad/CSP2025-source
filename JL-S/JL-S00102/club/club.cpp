#include <bits/stdc++.h>
using namespace std;
int t,n,a,b,c,l1,l2,l3,res;
struct node{
    int a,b,c;
    int ma,mi,m;
};
bool compare(node x,node y){
    return x.m<y.m;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t){
        l1=0,l2=0,l3=0,res=0;
        node dep[3][10005],e;
        cin>>n;
        for (int i=0;i<n;i++){
            cin>>e.a>>e.b>>e.c;
            e.ma=max(e.a,max(e.b,e.c));
            e.mi=min(e.a,min(e.b,e.c));
            e.m=e.ma-(e.a+e.b+e.c-e.ma-e.mi);
            if (e.ma==e.a){dep[0][l1]=e;l1++;}
            if (e.ma==e.b){dep[1][l2]=e;l2++;}
            if (e.ma==e.c){dep[2][l3]=e;l3++;}
            res+=e.ma;
        }
        if (l1>n/2){
            sort(dep[0],dep[0]+l1,compare);
            for (int i=0;i<l1-n/2;i++) res-=dep[0][i].m;
        }
        else{
            if (l2>n/2){
                sort(dep[1],dep[1]+l2,compare);
                for (int i=0;i<l2-n/2;i++) res-=dep[1][i].m;
            }
            else{
                sort(dep[2],dep[2]+l3,compare);
                for (int i=0;i<l3-n/2;i++) res-=dep[2][i].m;
            }
        }
        cout<<res<<endl;
        t--;
    }
    return 0;
}

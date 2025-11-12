#include <iostream>
#include <algorithm>
using namespace std;
struct ro{
    int fr;
    int to;
    int w;
}r[1000006];
//vector <node>t[10055];
bool cmp(ro t1,ro t2){
    return t1.w<t2.w;
}
int n,m,k;
int ontr[100206];
int trs=0;
int siz=0;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<m;i++){
        ro tt;
        scanf("%d%d%d",&tt.fr,&tt.to,&tt.w);
        r[i]=tt;
    }
    for(int i=1;i<=k;i++){
         int ww;
        cin>>ww;
        for(int j=1;i<=n;j++){

            scanf("%d",&ww);
            r[m+j].fr=j;
            r[m+j].to=n+i;
            r[m+j].w=ww;
        }
    }
    m=m+n*k;
    //zhuixiaoshengchengshu
    sort(r,r+m,cmp);
    for(int i=0;i<m;i++){
        cout<<r[i].fr<<" "<<r[i].to<<" "<<r[i].w<<endl;
    }
    int cnt=0;
    while(trs<n && cnt<=m){
            cout<<r[cnt].w<<" ";
        if(ontr[r[cnt].fr]==0 || ontr[r[cnt].to]==0){
            trs+=(ontr[r[cnt].fr]==0 && ontr[r[cnt].to]==0? 2:1);
            ontr[r[cnt].fr]=1;
            ontr[r[cnt].to]=1;
            siz+=r[cnt].w;

        }
        cnt++;
    }
    cout<<siz;
    return 0;
}

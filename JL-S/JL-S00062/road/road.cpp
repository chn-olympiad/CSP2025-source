#include<bits/stdc++.h>
using namespace std;
vector<int>ve;
vector<int>::iterator it;
bool cmp(int a,int b){
    return a<=b;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k,u,v,w,sum=0;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        scanf("%d %d %d",&u,&v,&w);
        ve.push_back(w);
    }
    for(int i=1;i<=k;i++){
        scanf("%d",&u);
        for(int j=1;j<=m;j++){
            scanf("%d",&v);
        }
    }
    sort(ve.begin(),ve.end(),cmp);
    for(it=ve.begin();it!=ve.end()-1;it++){
        sum+=*it;
    }
    printf("%d",sum);
    return 0;
}

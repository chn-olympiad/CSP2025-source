#include <bits/stdc++.h>
using namespace std;
const int maxn=100010;
int n,t;
struct the{
    int num,bu;
};
the a[maxn][5];
int ans;
bool cmp(the x,the y){
    return x.num>y.num;
}
int cmp2(int l){
    return a[l][1].num-a[l][2].num;
}
int per[5];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        memset(per,0,sizeof(per));
        cin>>n;
        ans=0;
        int maxp=-1;
        int pmax;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>a[i][j].num;
                a[i][j].bu=j;
            }
            sort(a[i]+1,a[i]+4,cmp);
            per[a[i][1].bu]++;
            if(maxp<per[a[i][1].bu]){
                pmax=a[i][1].bu;
                maxp=per[a[i][1].bu];
            }
            ans+=a[i][1].num;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n-i+1;j++){
                if(cmp2(i+1)<cmp2(i)){
                    swap(a[i],a[i+1]);
                }
            }
        }
        int line=n/2;
        if(maxp<=line){
            cout<<ans<<endl;
        }else{
            int unfinished=maxp-line;
            for(int i=1;i<=n;i++){
                if(a[i][1].bu==pmax&&unfinished){
                    unfinished--;
                    ans-=a[i][1].num;
                    if(per[a[i][2].bu]<=line)ans+=a[i][2].num;
                    else ans+=a[i][3].num;
                }
                if(!unfinished){
                    break;
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}

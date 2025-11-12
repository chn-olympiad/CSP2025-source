#include<bits/stdc++.h>
using namespace std;
int t,n,s;
struct{
    bool id;
    int a,b,c;
//Ren5Jie4Di4Ling5%
}ans[100005];
long long aw=0,ddd,aaa,bbb,ccc;
int bfs(int i){
    if(i>n){

        aw=max(aw,ddd);
        return 0;
    }
    //for(int i=1;i<=n;i++){
        if(ans[i].id==0){
            ans[i].id=1;
            if(aaa<s){

                aaa++;
                ddd+=ans[i].a;
                bfs(i+1);
                ddd-=ans[i].a;
                aaa--;
        }
        if(bbb<s){

            bbb++;
            ddd+=ans[i].b;
            bfs(i+1);
            ddd-=ans[i].b;
            bbb--;
        }
        if(ccc<s){

            ccc++;
            ddd+=ans[i].c;
            bfs(i+1);
            ddd-=ans[i].c;
            ccc--;
        }
        ans[i].id=0;
   // }


}}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        aaa=0,bbb=0,ccc=0,ddd=0;
        scanf("%d",&n);
        s=n/2;
        aw=0;
        for(int i=1;i<=n;i++){
            scanf("%d %d %d\n",&ans[i].a,&ans[i].b,&ans[i].c);

        }
        bfs(1);
        /*for(int i=1;i<=n;i++){
            answer+=max(max(ans[i].a,ans[i].b),ans[i].c);
        }


*/
        cout<<aw<<endl;
    }
    return 0;
}

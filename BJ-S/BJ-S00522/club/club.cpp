#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int a[100001][4];
int re_a[100001][4];
int ans[100001];//表示欸个人去往哪里
int k=1;
int cnt[100001];//每个社团的人数
int n;
long long res=0;
void calc(){
    long long num=0;
    for(int i=1;i<=n;i++){
        if(ans[i]==1){
            num+=a[i][1];
        }
        if(ans[i]==2){
            num+=a[i][2];
        }
        if(ans[i]==3){
            num+=a[i][3];
        }
    }
    res=max(res,num);
}
void dfs(int step,int N){
    if(step==N+1){
        calc();
    }
    for(int i=1;i<=3;i++){
        if(cnt[i]+1<=n/2){
            cnt[i]++;
            ans[k++]=i;
            dfs(step+1,N);
            ans[--k]=0;
            cnt[i]--;
        }
    }
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--){

        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            //re_a[i][1]=a[i][1]-(a[i][2]+a[i][3]);
            //re_a[i][2]=a[i][2]-(a[i][1]+a[i][3]);
            //re_a[i][3]=a[i][1]-(a[i][2]+a[i][3]);
        }
        memset(cnt,0,sizeof(cnt));
        memset(ans,0,sizeof(ans));
        dfs(1,n);
        cout<<res<<endl;;
        res=0;
    }
    return 0;
}

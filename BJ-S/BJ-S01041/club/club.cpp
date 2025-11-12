#include<bits/stdc++.h>
using namespace std;
int x;
const int N=1e5+10;
struct Node{
    int a,b,c;
};
int jadge[5];
int maxn=0;

int n;
Node node[N];
vector<int>text;
void dfs(int cnt,int sum){
    if(cnt>n){

        maxn=max(maxn,sum);
        return ;
    }

    for(int i=1;i<=3;i++){

        jadge[i]++;
        if(jadge[i]>n/2){
            jadge[i]--;
            continue;
        }
        //cout<<i<<' ';

        if(i==1)dfs(cnt+1,sum+node[cnt].a);
        if(i==2)dfs(cnt+1,sum+node[cnt].b);
        if(i==3)dfs(cnt+1,sum+node[cnt].c);
        jadge[i]--;


    }

}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>x;

    while(x--){
        cin>>n;

        for(int i=1;i<=n;i++){
            cin>>node[i].a>>node[i].b>>node[i].c;
        }
        for(int i=1;i<=3;i++)jadge[i]=0;
        //for(int i=1;i<=3;i++)cout<<jadge[i];
        dfs(0,0);
        cout<<maxn<<endl;
        maxn=0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

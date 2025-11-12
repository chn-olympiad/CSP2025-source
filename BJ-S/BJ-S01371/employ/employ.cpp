#include<bits/stdc++.h>
using namespace std;
const int N=505;
int n,m,s[N],c[N];
string S;
const int mod=998244353;
bool flag1=true;
int choose[N];
bool vis[N];
int answer=0;
void DFS(int step){
    if(step<n){
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                vis[i]=true;
                choose[step]=i;
                if(step<n){
                    DFS(step+1);
                }
                vis[i]=false;
            }
        }
    }
    int no=0,yes=0;
    if(step==n){
        for(int i=1;i<=n;i++){
            vis[choose[i]]=false;
        }
        for(int i=1;i<=n;i++){
            if(vis[i]){
                choose[n]=i;
                break;
            }
        }
        for(int i=1;i<=n;i++){
            vis[i]=true;

        }
        for(int i=1;i<=n;i++){
            if(s[i]==0){
                no++;
            }
            else{
                if(c[choose[i]]<=no){
                    no++;
                }
                else{
                    yes++;
                }
            }
        }
        if(yes>=m){
            answer++;
        }
        return;
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    memset(vis,false,sizeof vis);
    DFS(0);
    printf("%d\n",answer);
    return 0;
}

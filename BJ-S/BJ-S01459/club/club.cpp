#include <bits/stdc++.h>
using namespace std;
int n;
int num=0;
int a1,a2,a3;
struct awa{
    int x;
    int y;
    int z;
 //   int d;
    bool bian;
}g[100001];
int xian;
//std::set<int> amin;
void dfs(int q,int w,int a,int b,int c,int ans){
    if(a==xian&&b==xian&&c==xian){
        num=max(num,ans);
        return ;
    }
    else if(q>n||w>3||w<1){
    num=max(num,ans);
        return;
    }
    else{

        if(w==1&&a<xian){ans=ans+g[q].x;
        //cout <<q<<" "<<w<<" "<<a<<b<<c<<" "<<ans<<endl;

            a++;
           dfs(q+1,w,a,b,c,ans);
           dfs(q+1,w+1,a,b,c,ans);
           dfs(q+1,w+2,a,b,c,ans);
           return ;
        }
        else if(w==2&&b<xian){ans=ans+g[q].y;
            //cout <<q<<" "<<w<<" "<<a<<b<<c<<" "<<ans<<endl;

            b++;
            dfs(q+1,w-1,a,b,c,ans);
           dfs(q+1,w,a,b,c,ans);
           dfs(q+1,w+1,a,b,c,ans);
           return ;
        }
        else if(w==3&&c<xian){ans=ans+g[q].z;
            //cout <<q<<" "<<w<<" "<<a<<b<<c<<" "<<ans<<endl;

            c++;
            dfs(q+1,w,a,b,c,ans);
           dfs(q+1,w-1,a,b,c,ans);
           dfs(q+1,w-2,a,b,c,ans);
           return ;
        }
        else{
            num=max(num,ans);
            //cout <<endl<<endl;
            return ;
        }

    }
}

bool cmp(awa x,awa y){

    return x.x>y.x;
}

int dp[100001];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin >>t;
    for(int T=1;T<=t;T++){
            int ans1=0;
    num=0;
        bool flag=true;
        cin >>n;
        xian=n/2;
        for(int i=1;i<=n;i++){
            cin >>a1>>a2>>a3;
            g[i].x=a1;
            g[i].y=a2;
            g[i].z=a3;
            if(a2!=0||a3!=0){
                flag=false;
            }
            //g[i].d=max(a1,max(a2,a3));
        }
        if(flag){
            sort(g+1,g+n+1,cmp);
            for(int i=1;i<=xian;i++){
                //cout<<g[i].x;
                ans1=ans1+g[i].x;
            }
            cout <<ans1;
        }
        else{
            dfs(1,1,0,0,0,0);
            dfs(1,2,0,0,0,0);
            dfs(1,3,0,0,0,0);
            cout <<num<<endl;

        }
    }

return 0;
}

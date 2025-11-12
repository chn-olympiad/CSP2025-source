#include<iostream>
#include<algorithm>
using namespace std;
int t;
int ans;
int n;
struct node{
    int a,b,c;
}s[100005];
bool flag=1;
int cnt[4];
bool cmp(node x,node y){
    return x.a>y.a;
}
void dfs(int x,int sum){
    if(x>n){
        ans=max(ans,sum);
        return ;
    }
    
    if(cnt[1]<n/2){
        ++cnt[1];
        dfs(x+1,sum+s[x].a);
        --cnt[1];
    }
    if(cnt[2]<n/2){
        ++cnt[2];
        dfs(x+1,sum+s[x].b);
        --cnt[2];
    }
    if(cnt[3]<n/2){
        ++cnt[3];
        dfs(x+1,sum+s[x].c);
        --cnt[3];
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        ans=0;
        cnt[1]=cnt[2]=cnt[3]=0;
        cin>>n;
        for(int i=1;i<=n;++i){
            cin>>s[i].a>>s[i].b>>s[i].c;
            if(s[i].b||s[i].c){
                flag=0;
            }
        }
        if(flag){
            sort(s+1,s+1+n,cmp);
            for(int i=1;i<=n/2;++i){
                ans+=s[i].a;
            }cout<<ans<<endl;
        }
        if(n<=30){
            dfs(1,0);
            cout<<ans<<endl;
        }
    }
    return 0;
}
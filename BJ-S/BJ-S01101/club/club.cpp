#include <bits/stdc++.h>
using namespace std;
struct p{
    int c1,c2,c3,id;
}a[100001];
int T,n;
long long maxx;
void dfs(int in,long long cnt,int cnt1,int cnt2,int cnt3){
    if(in>n){
        maxx=max(maxx,cnt);
        return;
    }
    if(cnt1<n/2){
        dfs(in+1,cnt+a[in].c1,cnt1+1,cnt2,cnt3);
    }
    if(cnt2<n/2){
        dfs(in+1,cnt+a[in].c2,cnt1,cnt2+1,cnt3);
    }
    if(cnt3<n/2){
        dfs(in+1,cnt+a[in].c3,cnt1,cnt2,cnt3+1);
    }
}
bool cmp(p a,p b){
    return a.c1>b.c1;
}
bool cmp2(p a,p b){
    return max(a.c1,a.c2)>max(b.c1,b.c2);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        bool A=true,B=true;
        for(int i=1;i<=n;i++){
            cin>>a[i].c1>>a[i].c2>>a[i].c3;
            a[i].id=i;
            if(a[i].c2!=0||a[i].c3!=0){
                A=false;
            }
            if(a[i].c3!=0){
                B=false;
                A=false;
            }
        }
        if(A){
            sort(a+1,a+n+1,cmp);
            for(int i=1;i<=n/2;i++){
                maxx+=a[i].c1;
            }
            cout<<maxx<<endl;
            continue;
        }
        if(B){
            bool vis[100001];
            int cnt1=0,cnt2=0,cnt=0;
            int c1=0,c2=0;
            memset(vis,0,sizeof(vis));
            sort(a+1,a+n+1,cmp2);
            for(int i=1;i<=n;i++){
                if(a[i].c1>=a[i].c2&&cnt1<n/2){
                    cnt1++;
                    maxx+=a[i].c1;
                    vis[a[i].id]=true;
                    continue;
                }
                if(a[i].c2>a[i].c1&&cnt2<n/2){
                    cnt2++;
                    maxx+=a[i].c2;
                    vis[a[i].id]=true;
                    continue;
                }
            }
            cout<<maxx<<endl;
            continue;
        }
        maxx=0;
        dfs(1,0,0,0,0);
        cout<<maxx<<endl;
    }
    return 0;
}

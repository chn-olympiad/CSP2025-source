#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n,ans;
bool vis[100005];
struct node{
    int a,b,c,id;
}sat[100005];
bool cmp1(node x,node y){
    return min(x.a-x.b,x.a-x.c)>min(y.a-y.b,y.a-y.c);
}
bool cmp2(node x,node y){
    return min(x.b-x.c,x.b-x.a)>min(y.b-y.c,y.b-y.a);
}
bool cmp3(node x,node y){
    return min(x.c-x.b,x.c-x.a)>min(y.c-y.b,y.c-y.a);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        memset(vis,false,sizeof(vis));
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++)
            sat[i].id=i;
        for(int i=1;i<=n;i++)
            scanf("%d%d%d",&sat[i].a,&sat[i].b,&sat[i].c);
        int cnt1=0,cnt2=0,cnt3=0;
        sort(sat+1,sat+1+n,cmp1);
        for(int i=1;i<=n;i++){
            if(min(sat[i].a-sat[i].b,sat[i].a-sat[i].c)>0||!vis[sat[i].id]&&(min(sat[i].a-sat[i].b,sat[i].a-sat[i].c))==0&&i<=n/2){
                if(cnt1<n/2){
                    cnt1++;
                    vis[sat[i].id]=true;
                    ans+=sat[i].a;
                }else{
                    if(min(sat[i].b-sat[i].c,sat[i].b-sat[i].a)>min(sat[i].c-sat[i].b,sat[i].c-sat[i].a)){
                        cnt2++;
                        vis[sat[i].id]=true;
                        ans+=sat[i].b;
                    }else{
                        cnt3++;
                        vis[sat[i].id]=true;
                        ans+=sat[i].c;
                    }
                }
            }else
                break;
        }
//        cout<<ans<<endl;
        sort(sat+1,sat+1+n,cmp2);
        for(int i=1;i<=n;i++){
            if(min(sat[i].b-sat[i].c,sat[i].b-sat[i].a)>0||!vis[sat[i].id]&&min(sat[i].b-sat[i].c,sat[i].b-sat[i].a)==0&&i<=n/2){
                if(cnt2<n/2){
                    cnt2++;
                    vis[sat[i].id]=true;
                    ans+=sat[i].b;
                }else{
                    if(min(sat[i].a-sat[i].b,sat[i].a-sat[i].c)>min(sat[i].c-sat[i].b,sat[i].c-sat[i].a)){
                        cnt1++;
                        vis[sat[i].id]=true;
                        ans+=sat[i].a;
                    }else{
                        cnt3++;
                        vis[sat[i].id]=true;
                        ans+=sat[i].c;
                    }
                }
            }else
                break;
        }
//        cout<<ans<<endl;
        sort(sat+1,sat+1+n,cmp3);
        for(int i=1;i<=n;i++){
            if(min(sat[i].c-sat[i].b,sat[i].c-sat[i].a)>0||!vis[sat[i].id]&&min(sat[i].c-sat[i].b,sat[i].c-sat[i].a)==0&&i<=n/2){
                if(cnt3<n/2){
                    cnt3++;
                    vis[sat[i].id]=true;
                    ans+=sat[i].c;
                }else{
                    if(min(sat[i].a-sat[i].c,sat[i].a-sat[i].b)>min(sat[i].b-sat[i].c,sat[i].b-sat[i].a)){
                        cnt1++;
                        vis[sat[i].id]=true;
                        ans+=sat[i].a;
                    }else{
                        cnt2++;
                        vis[sat[i].id]=true;
                        ans+=sat[i].b;
                    }
                }
            }else
                break;
        }
        for(int i=1;i<=n;i++)
            if(!vis[sat[i].id])
                ans+=max(sat[i].a,max(sat[i].b,sat[i].c));
        cout<<ans<<endl;
    }
    return 0;
}

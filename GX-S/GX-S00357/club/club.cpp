#include<bits/stdc++.h>
using namespace std;
int n,m,ans=0,ans1=0,ma=0;
int cnt[4],ww[1000007],t,flag=1;
struct Node{
    int a,b,c,id1,id2,id3,wz1,wz2,wz3;
}s[1000007];
bool cmp(Node x,Node y){
    return x.id1>y.id1;
}
bool cmpa(Node x,Node y){
    return x.a>y.a;
}
void dfs(int cnt,int w1,int w2,int w3){
    if(cnt>n+1||w1>m||w2>m||w3>m){
        return;
    }
    if(cnt==n+1){
        ans1=0;
        for(int i=0;i<cnt;i++){
            if(ww[i]==1){
                ans1+=s[i].a;
            }
            if(ww[i]==2){
                ans1+=s[i].b;
            }
            if(ww[i]==3){
                ans1+=s[i].c;
            }
        }
        ma=max(ma,ans1);
        return;
    }
    for(int i=1;i<=n;i++){
        ww[cnt]=1;
        dfs(cnt+1,w1+1,w2,w3);
        ww[cnt]=2;
        dfs(cnt+1,w1,w2+1,w3);
        ww[cnt]=3;
        dfs(cnt+1,w1,w2,w3+1);
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        flag=1;
        cin>>n;
        if(n<=10){
            m=n/2;
            for(int i=1;i<=n;i++){
                cin>>s[i].a>>s[i].b>>s[i].c;
                if(s[i].b!=0||s[i].c!=0){
                    flag=0;
                }
            }
            if(flag==1){
                sort(s+1,s+n+1,cmpa);
                cout<<s[1].a<<endl;
                continue;
            }
            dfs(1,0,0,0);
            cout<<ma<<endl;
            ma=0;
        }else{
            m=n/2;
            cnt[1]=0;cnt[2]=0;cnt[3]=0;
            for(int i=1;i<=n;i++){
                int m1,m2,m3,w1,w2,w3;
                cin>>s[i].a>>s[i].b>>s[i].c;
                if(s[i].b!=0||s[i].c!=0){
                    flag=0;
                }
                m1=max(max(s[i].a,s[i].b),s[i].c);
                m3=min(min(s[i].a,s[i].b),s[i].c);
                if(m1==s[i].a&&m3==s[i].b){
                    m2=s[i].c;
                    w1=1;w2=3;w3=2;
                }
                else if(m1==s[i].a&&m3==s[i].c){
                    m2=s[i].b;
                    w1=1;w2=2;w3=3;
                }
                else if(m1==s[i].b&&m3==s[i].a){
                    m2=s[i].c;
                    w1=2;w2=3;w3=1;
                }
                else if(m1==s[i].b&&m3==s[i].c){
                    m2=s[i].a;
                    w1=2;w2=1;w3=3;
                }
                else if(m1==s[i].c&&m3==s[i].a){
                    m2=s[i].b;
                    w1=3;w2=2;w3=1;
                }
                else if(m1==s[i].c&&m3==s[i].b){
                    m2=s[i].a;
                    w1=3;w2=1;w3=2;
                }
                s[i].id1=m1;
                s[i].id2=m2;
                s[i].id3=m3;
                s[i].wz1=w1;
                s[i].wz2=w2;
                s[i].wz3=w3;
            }
            if(flag==1){
                sort(s+1,s+n+1,cmpa);
                cout<<s[1].a<<endl;
                continue;
            }
            sort(s+1,s+n+1,cmp);
            for(int i=1;i<=n;i++){
                ans+=s[i].id1;
                cnt[s[i].wz1]++;
                if(cnt[s[i].wz1]>m){
                    ans-=s[i].id1;
                    cnt[s[i].wz1]--;
                }else{
                    continue;
                }
                ans+=s[i].id2;
                cnt[s[i].wz2]++;
                if(cnt[s[i].wz2]>m){
                    ans-=s[i].id2;
                    cnt[s[i].wz2]--;
                }else{
                    continue;
                }
                ans+=s[i].id3;
                cnt[s[i].wz3]++;
                if(cnt[s[i].wz3]>m){
                    ans-=s[i].id3;
                    cnt[s[i].wz3]--;
                }else{
                    continue;
                }
            }
            cout<<ans<<endl;
            ans=0;
        }
    }
    return 0;
}

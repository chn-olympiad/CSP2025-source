#include<bits/stdc++.h>
using namespace std;
#define long long ll
struct stu{
    int a,b,c,ma,mid,mi,maxx,minn,midd;
}s[100005];
int ddd[4];
int t,n;
bool check(int n){
    return ddd[1]<=n/2&&ddd[2]<=n/2&&ddd[3]<=n/2;
}
bool cmp(stu p,stu l){
    return p.a>l.a;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);    
        ddd[1]=ddd[2]=ddd[3]=0; 
        int ans=0;
        bool A=1;
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&s[i].a,&s[i].b,&s[i].c);
            if(A||s[i].b!=0||s[i].c!=0) A=0;
            s[i].maxx=max(s[i].a,max(s[i].b,s[i].c)),s[i].minn=min(s[i].a,min(s[i].b,s[i].c));
            s[i].midd=s[i].a+s[i].b+s[i].c-s[i].maxx-s[i].minn;
            if(s[i].a>=s[i].b){
                if(s[i].b>=s[i].c) s[i].ma=1,s[i].mid=2,s[i].mi=3;
                else if(s[i].a>=s[i].c) s[i].ma=1,s[i].mid=3,s[i].mi=2;
                else s[i].ma=3,s[i].mid=1,s[i].mi=2;
            }else{
                if(s[i].a>=s[i].c) s[i].ma=2,s[i].mid=1,s[i].mi=3;
                else if(s[i].b>=s[i].c) s[i].ma=2,s[i].mid=3,s[i].mi=1;
                else s[i].ma=3,s[i].mid=2,s[i].mi=1;
            }
            ddd[s[i].ma]++;
            ans+=s[i].maxx;
        }
        if(A){
            int ans=0;
            sort(s+1,s+n+1,cmp);
            for(int i=1;i<=n/2;i++) ans+=s[i].a;  
            printf("%d\n",ans);
            continue;
        }
        while(!check(n)){
            int mmm=-1,mmmm=INT_MAX;
            for(int i=1;i<=n;i++) if(s[i].maxx>=s[i].midd) mmmm=min(mmmm,s[i].maxx-s[i].midd),mmm=(mmmm==s[i].maxx-s[i].midd?i:mmm);
            ans-=mmmm;
            ddd[s[mmm].ma]--,ddd[s[mmm].mid]++;
            swap(s[mmm].maxx,s[mmm].minn),swap(s[mmm].maxx,s[mmm].midd);
            swap(s[mmm].ma,s[mmm].mi),swap(s[mmm].ma,s[mmm].mid);
        }
        printf("%d\n",ans);
    }
    return 0;
}
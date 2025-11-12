#include<bits/stdc++.h>
using namespace std;
int t;
int n,ans,tot;
struct s{
    int maxn,id,ke;
    int b,c;
};
int first[100005],second[100005],third[100005];
bool cmp(s x,s y){
    return x.maxn>y.maxn;
}
void dfs(int x,int l1,int l2,int l3,int sum){
        if(x==n+1){
            tot=max(tot,sum);
        }
        if(l1<n/2)dfs(x+1,l1+1,l2,l3,sum+first[x]);
        if(l2<n/2)dfs(x+1,l1,l2+1,l3,sum+second[x]);
        if(l3<n/2)dfs(x+1,l1,l2,l3+1,sum+third[x]);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
            tot=0;
        ans=0;
        cin>>n;
        s t[100005];
        int l1=n,l2=0,l3=0;
        bool b2=1,b3=1;
        for(int i=1;i<=n;i++){
            int a,b,c;
            cin>>a>>b>>c;
            first[i]=a;
            second[i]=b;
            third[i]=c;
            if(b!=0)b2=0;
            if(c!=0)b3=0;
            ans+=a;
            b-=a;c-=a;
            t[i].ke=i;
            if(b>c)t[i].maxn=b,t[i].id=2;
            if(b<c)t[i].maxn=c,t[i].id=3;
            if(b==c)t[i].maxn=b,t[i].id=0;
            t[i].b=b;
            t[i].c=c;


        }
        if(n<=30){
            dfs(1,0,0,0,0);
            cout<<tot<<endl;
        }
        else if(b3&&b2){
            sort(first+1,first+n+1);
            for(int i=n;i>n/2;i--)tot+=first[i];
            cout<<tot<<endl;
        }
        else {
            sort(t+1,t+n+1,cmp);
            for(int i=1;i<=n;i++){

                if(t[i].maxn<=0&&l1<=n/2){
                    break;
                }
                if(t[i].id==2&&l2<n/2){
                    ans+=t[i].b;
                    l2++;l1--;
                }
                if(t[i].id==3&&l3<n/2){
                    ans+=t[i].c;
                    l3++;l1--;

                }
                if(t[i].id==0){
                    if(l2<l3){
                        ans+=t[i].b;
                        l2++;l1--;
                    }
                    else {
                        ans+=t[i].c;
                        l3++;l1--;

                    }
                }

            }
            cout<<ans<<endl;
        }
    }
    return 0;
}

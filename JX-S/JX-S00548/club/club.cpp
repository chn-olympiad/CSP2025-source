#include<bits/stdc++.h>
using namespace std;
struct hh{
    int num,id;
};
long long ans=0;
hh a[100005][5];
hh g[100005],p[100005],s[100005];
int b[100005];
bool cmp(hh a,hh b){
    return a.num>b.num;
}
int main(){
    //freopen("club.in","r",stdin);
    //freopen("club.out","w",stdout);
    int t;
    cin>>t;
    int n,x,y,z,maxn=0;
    while(t--){
        maxn=0;
        ans=0;
        int g1=0,p1=0,s1=0;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(g,0,sizeof(g));
        memset(p,0,sizeof(p));
        memset(s,0,sizeof(s));
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>x>>y>>z;
            a[i][1].num=max(x,max(y,z));
            a[i][3].num=min(x,min(y,z));
                g[i-1].num=x;
                g[i-1].id=i;
                p[i-1].id=i;
                s[i-1].id=i;
                p[i-1].num=y;
                s[i-1].num=z;
            if(a[i][1].num==x&&a[i][3].num==z){
                a[i][2].num=y;
                a[i][1].id=1;
                a[i][2].id=2;
                a[i][3].id=3;
            }else if(a[i][1].num==x&&a[i][3].num==y){
                a[i][2].num=z;
                a[i][1].id=1;
                a[i][2].id=3;
                a[i][3].id=2;
            }else if(a[i][1].num==y&&a[i][3].num==z){
                a[i][2].num=x;
                a[i][1].id=2;
                a[i][2].id=1;
                a[i][3].id=3;
            }else if(a[i][1].num==y&&a[i][3].num==x){
                a[i][2].num=z;
                a[i][1].id=2;
                a[i][2].id=3;
                a[i][3].id=1;
            }else if(a[i][1].num==z&&a[i][3].num==x){
                a[i][2].num=y;
                a[i][1].id=3;
                a[i][2].id=2;
                a[i][3].id=1;
            }else if(a[i][1].num==z&&a[i][3].num==y){
                a[i][2].num=x;
                a[i][1].id=3;
                a[i][2].id=1;
                a[i][3].id=2;
            }
        }
        sort(g,g+n,cmp);
        sort(p,p+n,cmp);
        sort(s,s+n,cmp);
        int man[4]={0};
        int n1=n;
        if(n==2){
            if(a[1][1].id!=a[2][1].id){
                ans+=a[1][1].num;
            }else{
                ans+=max(a[1][1].num+a[2][2].num,max(a[1][1].num+a[2][3].num,max(a[1][2].num+a[2][1].num,max(a[1][2].num+a[2][3].num,max(a[1][3].num+a[2][1].num,a[1][3].num+a[2][2].num)))));
            }
        }else{
        while(n!=0){
            int maxn=max(g[g1].num,max(p[p1].num,s[s1].num));
            if(maxn==g[g1].num){
                    if(man[1]+1<=n1/2&&b[g[g1].id]==0){
                        b[g[g1].id]=1;
                        man[1]++;
                        ans+=maxn;
                    }n--;
                    g1++;
            }else if(maxn==p[p1].num){
                if(man[2]+1<=n1/2&&b[p[p1].id]==0){
                    b[p[p1].id]=1;
                    man[2]++;
                    ans+=maxn;
                    }n--;
                    p1++;
            }else if(maxn==s[s1].num){
                    if(man[3]+1<=n1/2&&b[s[s1].id]==0){
                    b[s[s1].id]=1;
                    man[3]++;
                    ans+=maxn;
                    }
                    n--;
                    s1++;
            }
        }
    }
        cout<<ans<<endl;
    }
    return 0;
}

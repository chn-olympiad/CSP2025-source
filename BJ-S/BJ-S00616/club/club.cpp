#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,ans;
struct student{
    bool xuan=1;
    int m1;
    int m2;
    int m3;
    int maxx=0;
    int maxxb;
    int maxbh;

}stu[1000005];

void stop(int bh){
for(int i=0;i<n;i++){
    if(bh==1)
        stu[i].m1=-10000;
    else if(bh==2)
        stu[i].m2=-10000;
    else if(bh==3)
        stu[i].m3=-10000;
    stu[i].maxx=max(max(stu[i].m1,stu[i].m2),stu[i].m3);
            if(stu[i].m1==stu[i].maxx)
                    stu[i].maxxb=max(stu[i].m2,stu[i].m3);
            else if(stu[i].m2==stu[i].maxx)
                    stu[i].maxxb=max(stu[i].m2,stu[i].m3);
            else if(stu[i].m3==stu[i].maxx)
                    stu[i].maxxb=max(stu[i].m2,stu[i].m1);
            if(stu[i].maxx=stu[i].m1)
                stu[i].maxbh=1;
            else if(stu[i].maxx=stu[i].m2)
                stu[i].maxbh=2;
            else
                stu[i].maxbh=3;
}
return ;
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int z=1;z<=t;z++){
        bool tp=1;
        ans=0;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>stu[i].m1>>stu[i].m2>>stu[i].m3;
            if(stu[i].m2!=0||stu[i].m3!=0)
                tp=0;
            stu[i].xuan=1;
            stu[i].maxx=max(max(stu[i].m1,stu[i].m2),stu[i].m3);
            if(stu[i].m1==stu[i].maxx)
                    stu[i].maxxb=max(stu[i].m2,stu[i].m3);
            else if(stu[i].m2==stu[i].maxx)
                    stu[i].maxxb=max(stu[i].m1,stu[i].m3);
            else if(stu[i].m3==stu[i].maxx)
                    stu[i].maxxb=max(stu[i].m2,stu[i].m1);
            if(stu[i].maxx==stu[i].m1)
                stu[i].maxbh=1;
            else if(stu[i].maxx==stu[i].m2)
                stu[i].maxbh=2;
            else
                stu[i].maxbh=3;
        }
        if(n==2){
            ans+=max(stu[0].maxx,stu[1].maxx);
            int ddd;
            if(stu[0].maxx==ans)
                ddd=0;
            else
                ddd=1;
            if(ddd=0){
                if(stu[0].maxbh==stu[1].maxbh){
                    ans+=stu[1].maxxb;
                }
                else
                    ans+=stu[1].maxx;
            }
            if(ddd=1){
                if(stu[0].maxbh==stu[1].maxbh){
                    ans+=stu[0].maxxb;
                }
                else
                    ans+=stu[0].maxx;
            }
            cout<<ans;
            return 0;
        }
    if(tp){
        ll ss[n+5];
        for(int i=0;i<n;i++){
            ss[i]=stu[i].m1;
        }
        sort(ss,ss+n);
        ll aans=0;
        for(int i=n-1;i>=n/2;i--){
            aans+=ss[i];
        }
        cout<<aans;
        return 0;
    }
        ll xz=n/2;
        int rs[3]={0,0,0};
        bool can[3]={1,1,1};
        for(int i=1;i<=n*n;i++){
            ll maxm=0,maxb,maxy=10000;
            for(int i=0;i<n;i++){
                if(stu[i].xuan&&stu[i].maxx>maxm){
                    maxm=stu[i].maxx;
                    maxb=i;
                    maxy=stu[i].maxxb;
                }
                if(stu[i].xuan&&stu[i].maxx==maxm){
                    if(stu[i].maxxb<maxy){
                        maxm=stu[i].maxx;
                        maxb=i;
                        maxy=stu[i].maxxb;
                    }
                }
            }

            ans+=maxm;
            rs[stu[maxb].maxbh]++;
            stu[maxb].xuan=0;
            if(rs[stu[maxb].maxbh]==xz)
                stop(stu[maxb].maxbh);
        }
        cout<<ans<<endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
struct peo{
    int p,ke;
}a[100005][3];
peo t[3];
int cha[100005];

bool cmp(const peo &a,const peo &b){
    return a.p>b.p;
}

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    for(int i=1;i<=T;i++){
        memset(cha,0,sizeof(cha));
        int n;
        long long ans=0;
        cin>>n;
        for(int j=1;j<=n;j++){
            memset(a[j],0,sizeof(a[j]));
        }
        int flag[4];
        memset(flag,0,sizeof(flag));
        for(int j=1;j<=n;j++){
            memset(t,0,sizeof(t));
            for(int k=0;k<3;k++){
                cin>>t[k].p;
                t[k].ke=k+1;
            }
            sort(t,t+3,cmp);
            for(int k=1;k<=2;k++){
                a[j][k].p=t[k-1].p;
                a[j][k].ke=t[k-1].ke;
            }
            ans+=a[j][1].p;
            flag[a[j][1].ke]++;
            cha[j]=a[j][1].p-a[j][2].p;
        }
        for(int j=1;j<=3;j++){
            if(flag[j] > n/2){
                priority_queue<int,vector<int>,greater<int>> q;
                for(int k=1;k<=n;k++){
                    if(a[k][1].ke==j){
                        q.push(cha[k]);
                    }
                }
                while(flag[j] > n/2){
                    ans-=q.top();
                    q.pop();
                    flag[j]--;
                }
                continue;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

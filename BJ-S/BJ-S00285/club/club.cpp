#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct node{
    int a1,a2,a3,maxn1,maxn2,maxn3,m1,m2,m3,c1,c2,c3;
    bool f1,f2,f3;
    bool operator>(const node &a) const{
        if(c1!=a.c1){
            return c1>a.c1;
        }
        if(c2!=a.c2){
            return c2>a.c2;
        }
        return c3>a.c3;
    }
}a[N];
bool cmp(node a,node b){
    if(a.a1!=b.a1) return a.a1>b.a1;
    if(a.a2!=b.a2) return a.a2>b.a2;
    if(a.a3!=b.a3) return a.a3>b.a3;
}
int t,n,maxn,s[10];
priority_queue<node,vector<node>,greater<node> > q[10];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--){
        bool flag=0;
        memset(a,0,sizeof(a));
        memset(s,0,sizeof(s));
        int ans=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            maxn=0;
            cin>>a[i].a1>>a[i].a2>>a[i].a3;
            if(a[i].a2!=0||a[i].a3!=0){
                flag=1;
            }
            maxn=max(maxn,a[i].a1);
            maxn=max(maxn,a[i].a2);
            maxn=max(maxn,a[i].a3);
            a[i].maxn1=maxn;
            if(maxn=a[i].a1){
                a[i].maxn2=max(a[i].a2,a[i].a3);
                a[i].maxn3=min(a[i].a2,a[i].a3);
            }
            if(maxn=a[i].a2){
                a[i].maxn2=max(a[i].a1,a[i].a3);
                a[i].maxn3=min(a[i].a1,a[i].a3);
            }
            if(maxn=a[i].a3){
                a[i].maxn2=max(a[i].a2,a[i].a1);
                a[i].maxn3=min(a[i].a2,a[i].a1);
            }
            if(a[i].maxn1==a[i].a1){
                a[i].m1=1;
                // cout<<a[i].m1<<" ";
            }
            else if(a[i].maxn1==a[i].a2){
                a[i].m1=2;
                // cout<<a[i].m1<<" ";
            }
            else if(a[i].maxn1==a[i].a3){
                a[i].m1=3;
                // cout<<a[i].m1<<" ";
            }
            else if(a[i].maxn2==a[i].a1){
                a[i].m2=1;
                // cout<<a[i].m2<<" ";
            }
            else if(a[i].maxn2==a[i].a2){
                a[i].m2=2;
                // cout<<a[i].m2<<" ";
            }
            else if(a[i].maxn2==a[i].a3){
                a[i].m2=3;
                // cout<<a[i].m2<<" ";
            }
            else if(a[i].maxn3==a[i].a1){
                a[i].m3=1;
                // cout<<a[i].m3<<" ";
            }
            else if(a[i].maxn3==a[i].a2){
                a[i].m3=2;
                // cout<<a[i].m3<<" ";
            }
            else if(a[i].maxn3==a[i].a3){
                a[i].m3=3;
                // cout<<a[i].m3<<" ";
            }
            a[i].c1=a[i].maxn1-a[i].maxn2;
            a[i].c2=a[i].maxn2-a[i].maxn3;
            a[i].c3=a[i].maxn1-a[i].maxn3;
            // cout<<a[i].c1<<" "<<a[i].c2<<" "<<a[i].c3;
        }
        sort(a+1,a+n+1,cmp);

        if(flag==0){
            int sum=0;
            for(int i=1;i<=n/2;i++){
                sum+=a[i].a1;
                // return 0;
            }
            cout<<sum;
            return 0;
        }
        // for(int i=1;i<=n;i++){
        //     cout<<a[i].a2<<"\n";
        // }
        for(int i=1;i<=n;i++){
            if(s[a[i].m1]+1<=n/2){
                ans+=a[i].maxn1;
                s[a[i].m1]++;
                q[a[i].m1].push(a[i]);
            }
            else if(q[a[i].m1].top().maxn2+a[i].maxn1>ans){
                node tem=q[a[i].m1].top();
                q[a[i].m1].pop();
                q[a[i].m2].push(tem);
                ans=ans-tem.maxn1+a[i].maxn1+tem.maxn2;
            }
            else if(s[a[i].m2]+1<=n/2){
                ans+=a[i].maxn2;
                s[a[i].m2]++;
                q[a[i].m2].push(a[i]);
            }
            // else if(q[a[i].m2].top().maxn3+a[i].maxn2>ans){
            //     node tem=q[a[i].m2].top();
            //     q[a[i].m2].pop();
            //     q[a[i].m3].push(tem);
            //     ans=ans-tem.maxn1+a[i].maxn1+tem.maxn2;
            // }
            else if(q[a[i].m1].top().maxn3+a[i].maxn1>ans){
                node tem=q[a[i].m1].top();
                q[a[i].m1].pop();
                q[a[i].m3].push(tem);
                ans=ans-tem.maxn1+a[i].maxn1+tem.maxn3;
            }
            else if(s[a[i].m3]+1<=n/2){
                ans+=a[i].maxn3;
                s[a[i].m3]++;
            }
        }
        // for(int i=1;i<=q[3].size();i++){
        //     cout<<q[3].top().c1<<"\n";
        //     q[3].pop();
        // }
        cout<<ans<<" ";
    }
    return 0;
}
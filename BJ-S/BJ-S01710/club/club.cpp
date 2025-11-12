#include<bits/stdc++.h>
using namespace std;
struct nd{
    int x,y,z;
};
vector<nd>q;
int p,n;
void dfs(int u,int d,int k,int a,int b,int c){
    if(d>n)return;
    if(a>n/2||b>n/2||c>n/2)return;
    if(d<=n){
        p=max(p,k);
    }
    for(int i=u;i<n;i++){
        dfs(i+1,d+1,k+q[i].x,a+1,b,c);
        dfs(i+1,d+1,k+q[i].y,a,b+1,c);
        dfs(i+1,d+1,k+q[i].z,a,b,c+1);
    }
}
bool cmp(nd a,nd b){
    return a.x+a.y+a.z>b.x+b.y+b.z;
}
bool aa(nd a,nd b){
    return a.x>b.x;
}
void solve(){
    vector<nd>v=q;
    unsigned long long mx=0,k,q1,q2,q3;
    k=q1=q2=q3=0;
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<n;i++){
        if(max(max(v[i].x,v[i].y),v[i].z)==v[i].x){
            if(q1==n/2){
                if(max(v[i].y,v[i].z)==v[i].y){
                    if(q2==n/2)k+=v[i].z,q3++;
                    else k+=v[i].y,q2++;
                }else{
                    if(q3==n/2)k+=v[i].y,q2++;
                    else k+=v[i].z,q3++;
                }
            }else{
                k+=v[i].x,q1++;
            }
        }else if(max(max(v[i].x,v[i].y),v[i].z)==v[i].y){
            if(q2==n/2){
                if(max(v[i].x,v[i].z)==v[i].x){
                    if(q1==n/2)k+=v[i].z,q3++;
                    else k+=v[i].x,q1++;
                }else{
                    if(q3==n/2)k+=v[i].x,q1++;
                    else k+=v[i].z,q3++;
                }
            }else{
                k+=v[i].y,q2++;
            }
        }else{
            if(q3==n/2){
                if(max(v[i].y,v[i].x)==v[i].y){
                    if(q2==n/2)k+=v[i].x,q1++;
                    else k+=v[i].y,q2++;
                }else{
                    if(q1==n/2)k+=v[i].y,q2++;
                    else k+=v[i].x,q1++;
                }
            }else{
                k+=v[i].z,q3++;
            }
        }
    }
    cout<<k<<endl;
    mx=max(k,mx);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        p=0;
        q.resize(n);
        for(int i=0;i<n;i++)cin>>q[i].x>>q[i].y>>q[i].z;
        if(n<=10){
            dfs(0,0,0,0,0,0);
            cout<<p<<endl;
        }else if(q[0].y==0&&q[1].y==0&&q[2].y==0&&q[3].y==0){
            sort(q.begin(),q.end(),cmp);
            long long sum=0;
            for(int i=0;i<n/2;i++)sum+=q[i].x;
            cout<<sum<<endl;
        }else solve();
    }
    return 0;
}
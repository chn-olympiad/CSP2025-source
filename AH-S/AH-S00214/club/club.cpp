#include<bits/stdc++.h>
using namespace std;
#define N 100005
int t,n;
struct node{
    int x,y,z;
    int maxn;
    int mxy,myz,mxz,id;
}a[N];
int ans;
int b[5];
bool cmp(node x,node y){
    return x.maxn>y.maxn;
}
bool cmp1(node x,node y){
    return x.x>y.y;
}
bool cmp2(node x,node y){
    return x.y>y.y;
}
bool cmp3(node x,node y){
    return x.z>y.z;
}
bool cmp4(node x,node y){
    return x.mxy>y.mxy;
}
bool cmp5(node x,node y){
    return x.mxz>y.mxz;
}
bool cmp6(node x,node y){
    return x.myz>y.myz;
}
bool cmp7(node x,node y){
    return x.maxn<y.maxn;
}
bool cmp8(node x,node y){
    return x.x<y.y;
}
bool cmp9(node x,node y){
    return x.y<y.y;
}
bool cmp10(node x,node y){
    return x.z<y.z;
}
int cal(){
    long long sum=0;
    int flag=0,nxt=0x3f3f3f3f;
    memset(b,0,sizeof(b));
    for(int i=1;i<=n;i++){
        if(!flag){
            sum+=a[i].maxn;
            if(a[i].maxn==a[i].x)
                b[1]++;
            else if(a[i].maxn==a[i].y)
                b[2]++;
            else
                b[3]++;
        }
        if(b[1]==n/2){
            flag=1;
            sort(a+i+1,a+n+1,cmp6);
            nxt=i+1;
            break;
        }
        if(b[2]==n/2){
            flag=2;
            sort(a+i+1,a+n+1,cmp5);
            nxt=i+1;
            break;
        }
        if(b[3]==n/2){
            flag=3;
            sort(a+i+1,a+n+1,cmp4);
            nxt=i+1;
            break;
        }
    }
    for(int i=nxt;i<=n;i++){
        if(flag==1)
                sum+=a[i].myz;
            else if(flag==2)
                sum+=a[i].mxz;
            else    sum+=a[i].mxy;
    }
    return sum;
}
int dfs(int x){
    int sum=0;
    if(x==n+1) return 0;
    if(b[1]<n/2){
        b[1]++;
        sum=max(sum,a[x].x+dfs(x+1));
        b[1]--;
    }
    if(b[2]<n/2){
        b[2]++;
        sum=max(sum,a[x].y+dfs(x+1));
        b[2]--;
    }
    if(b[3]<n/2){
        b[3]++;
        sum=max(sum,a[x].z+dfs(x+1));
        b[3]--;
    }
    return sum;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        memset(b,0,sizeof(b));
        ans=0;
        for(int i=1;i<=n;i++){
            a[i].id=i;
            cin>>a[i].x>>a[i].y>>a[i].z;
            a[i].maxn=max(a[i].x,max(a[i].y,a[i].z));
            a[i].mxy=max(a[i].x,a[i].y);
            a[i].myz=max(a[i].y,a[i].z);
            a[i].mxz=max(a[i].x,a[i].z);
        }
        if(n<=16){
            cout<<dfs(1)<<endl;
        }else{
            ans=max(ans,cal());
            sort(a+1,a+n+1,cmp);
            ans=max(ans,cal());
            sort(a+1,a+n+1,cmp1);
            ans=max(ans,cal());
            sort(a+1,a+n+1,cmp2);
            ans=max(ans,cal());
            sort(a+1,a+n+1,cmp3);
            ans=max(ans,cal());
            sort(a+1,a+n+1,cmp4);
            ans=max(ans,cal());
            sort(a+1,a+n+1,cmp5);
            ans=max(ans,cal());
            sort(a+1,a+n+1,cmp6);
            ans=max(ans,cal());
            sort(a+1,a+n+1,cmp7);
            ans=max(ans,cal());
            sort(a+1,a+n+1,cmp8);
            ans=max(ans,cal());
            sort(a+1,a+n+1,cmp9);
            ans=max(ans,cal());
            sort(a+1,a+n+1,cmp10);
            ans=max(ans,cal());
            cout<<ans<<endl;
        }


    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

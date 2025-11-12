#include<iostream>
#define LL long long

using namespace std;

const int NR=1e5+10;
const int MR=1e5+10;

int n;

struct Node{
    int x,y,z;
}a[NR];

bool cmp(Node x,Node y){
    if(x.x==y.x)return x.y>y.y;
    return x.x>y.x;
}

LL ans=0;

void dfs(int step,int cnt1,int cnt2,int cnt3,LL sum){
    if(step>n){
        ans=max(ans,sum);
        return;
    }
    
    if(cnt1<n/2)dfs(step+1,cnt1+1,cnt2,cnt3,sum+a[step].x);
    if(cnt2<n/2)dfs(step+1,cnt1,cnt2+1,cnt3,sum+a[step].y);
    if(cnt3<n/2)dfs(step+1,cnt1,cnt2,cnt3+1,sum+a[step].z);
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin >> T;
    while(T--){
        cin >> n;
        for(int i=1;i<=n;i++){
            int x,y,z;
            cin >> x >> y >> z;
            //x-=z;y-=z;
            a[i]={x,y,z};
        }
        if(n<=10){
            ans=0;
            dfs(1,0,0,0,0);
            cout << ans << endl;
            continue;
        }
        sort(a+1,a+1+n,cmp);
        // int cnt1=0,cnt2=0,cnt3=0;
        // int ans1=0,ans=0,ans3=0;
        // for(int i=1;i<=n;i++){
        //     int x=a[i].x,y=a[i].y,z=a[i].z;
        
        // }
        
    }
}
#include<bits/stdc++.h>
using namespace std;
int n;
int a[100010][4];
int b[100010];
int ans;
int dfs(int now,int l1,int l2,int l3,int z){
     if(now==n){
        int i=-1;
        if(l1<n/2)i=max(i,z+a[now][1]);
        if(l2<n/2)i=max(i,z+a[now][2]);
        if(l3<n/2)i=max(i,z+a[now][3]);
        return i;
     }
     int i=-1;
     if(l1<n/2)i=max(i,dfs(now+1,l1+1,l2,l3,z+a[now][1]));
     if(l2<n/2)i=max(i,dfs(now+1,l1,l2+1,l3,z+a[now][2]));
     if(l3<n/2)i=max(i,dfs(now+1,l1,l2,l3+1,z+a[now][3]));
     return i;
}
int main(){

    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin >> t;
    for(int i=1;i<=t;i++){
        ans=0;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        int f=1;
        cin >> n;
        for(int i=1;i<=n;i++){
            cin >> a[i][1] >> a[i][2] >> a[i][3];
            if(a[i][2]!=0&&f>0)f=0;
            if(a[i][3]!=0&&f>0)f=0;

        }
        if(f==0){
            cout << dfs(0,0,0,0,0) << endl;
        }else if(f){
            for(int i=1;i<=n;i++)b[i]=a[i][1];
            sort(b+1,b+1+n);
            for(int i=n;i>n/2;i--)ans+=b[i];
            cout <<ans << endl;
        }
    }

    return 0;
}

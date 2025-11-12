#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10;
int t,n,m,mp[MAXN][4],maxx;
void f(int x,int a,int b,int c,int sum){
    if(a>n/2 || b>n/2 || c>n/2)return;
    if(x==n+1){
        maxx=max(maxx,sum);
        return;
    }
    f(x+1,a+1,b,c,sum+mp[x][1]);
    f(x+1,a,b+1,c,sum+mp[x][2]);
    f(x+1,a,b,c+1,sum+mp[x][3]);
}
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        maxx=0;
        cin>>n;
        bool flag=1;
        for(int i=1;i<=n;i++)for(int j=1;j<=3;j++){
            cin>>mp[i][j];
            if(j==1 || j==3)
                if(mp[i][j]!=0)
                    flag=0;
        }
        if(flag){
            f(0,0,0,0,0);
            cout<<maxx<<endl;
        }
        else {
            vector<int>a(n+1);
            int cnt=0;
            for(int i=1;i<=n;i++)a.push_back(max(mp[i][1],max(mp[i][2],mp[i][3])));
            sort(a.begin(),a.end(),cmp);
            for(int i=0;i<n/2;i++)cnt+=a[i];
            cout<<cnt<<endl;
        }
    }
    return 0;
}

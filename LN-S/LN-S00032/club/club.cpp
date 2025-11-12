#include <bits/stdc++.h>
using namespace std;
struct node{
    int a,b,c;
}a[100050];
int mem[202][101][101][101];
int t,n,ccc;
bool compa(node a,node b){
    return a.a>b.a;
}
int dfs(int s,int aa,int bb,int cc){
    if(s>n) return 0;
    if(mem[s][aa][bb][cc]!=-1){
        return mem[s][aa][bb][cc];
    }
    int maxx=0;
    if(aa<n/2){
        maxx=max(maxx,dfs(s+1,aa+1,bb,cc)+a[s].a);
    }
    if(bb<n/2){
        maxx=max(maxx,dfs(s+1,aa,bb+1,cc)+a[s].b);
    }
    if(!ccc&&cc<n/2){
        maxx=max(maxx,dfs(s+1,aa,bb,cc+1)+a[s].c);
    }
    return mem[s][aa][bb][cc]=maxx;
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t;
    while(t--){
        cin >> n;
        ccc=1;
        for(int i=1;i<=n;i++){
            cin >> a[i].a >> a[i].b >> a[i].c;
            if(a[i].c!=0){
                ccc=0;
            }
        }

        if(n>200){
            sort(a+1,a+n+1,compa);
            int ans=0;
            for(int i=1;i<=n/2;i++){
                ans+=a[i].a;
            }
            cout << ans << endl;
            continue;
        }
        memset(mem,-1,sizeof(mem));
        cout << dfs(1,0,0,0) << endl;



    }
    return 0;
}

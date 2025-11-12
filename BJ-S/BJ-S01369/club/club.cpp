#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
struct e{
    int a,b,c;
}n[N];
int m;
bool cmpa(e x,e y){
    return (x.a-max(x.b,x.c)) > (y.a-max(y.b,y.c));
}
bool cmpb(e x,e y){
    return (x.b-max(x.a,x.c)) > (y.b-max(y.a,y.c));
}
bool cmpc(e x,e y){
    return (x.c-max(x.a,x.b)) > (y.c-max(y.a,y.b));
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin >> T;
    while(T--){
        scanf("%d",&m);
        int mxa = 0,mxb = 0,mxc = 0;
        int ans = 0;
        for(int i=1;i<=m;i++){
            scanf("%d%d%d",&n[i].a,&n[i].b,&n[i].c);
            int k = max(n[i].a,max(n[i].b,n[i].c));
            ans += k;
            if(k == n[i].a)   mxa++;
            else if(k == n[i].b)  mxb++;
            else    mxc++;
        }
        int mx = max(mxa,max(mxb,mxc));
        if(mx <= m/2){
            cout << ans << endl;
            continue;
        }
        ans = 0;
        if(mx == mxa){
            sort(n+1,n+m+1,cmpa);
            for(int i=1;i<=m/2;i++)
                ans += n[i].a;
            for(int i=m/2+1;i<=m;i++)
                ans += max(n[i].b,n[i].c);
            cout << ans << endl;
        }
        if(mx == mxb){
            sort(n+1,n+m+1,cmpb);
            for(int i=1;i<=m/2;i++)
                ans += n[i].b;
            for(int i=m/2+1;i<=m;i++)
                ans += max(n[i].a,n[i].c);
            cout << ans << endl;
        }
        if(mx == mxc){
            sort(n+1,n+m+1,cmpc);
            for(int i=1;i<=m/2;i++)
                ans += n[i].c;
            for(int i=m/2+1;i<=m;i++)
                ans += max(n[i].b,n[i].a);
            cout << ans << endl;
        }
    }
    return 0;
}

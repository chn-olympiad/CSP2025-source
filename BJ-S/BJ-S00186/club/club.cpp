#include<bits/stdc++.h>
using namespace std;
#define int long long
struct Node{
    int a,b,c;
}aa[100005];
bool cmp1(Node x,Node y){
    return x.a-max(x.b,x.c) < y.a-max(y.b,y.c);
}
bool cmp2(Node x,Node y){
    return x.b-max(x.a,x.c) < y.b-max(y.a,y.c);
}
bool cmp3(Node x,Node y){
    return x.c-max(x.b,x.a) < y.c-max(y.b,y.a);
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin >> T;
    while(T--){
        int n, ans = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)cin >> aa[i].a >> aa[i].b >> aa[i].c;
        int na=0, nb=0, nc=0;
        for (int i = 1; i <= n; i++){
            if(aa[i].a >= aa[i].b && aa[i].a >= aa[i].c){
                ans+=aa[i].a;
                na++;
            }else if(aa[i].b >= aa[i].c && aa[i].b >= aa[i].c){
                ans+=aa[i].b;
                nb++;
            }else {
                ans+=aa[i].c;
                nc++;
            }
        }
        int maxn = n/2;
        if(na > maxn){
            sort(aa+1,aa+n+1,cmp1);
            for(int i = n-na+1; i <= maxn; i++){
                ans=ans-aa[i].a+max(aa[i].b,aa[i].c);
            }
        }else if(nb > maxn){
            sort(aa+1,aa+n+1,cmp2);
            for(int i = n-nb+1; i <= maxn; i++){
                ans=ans-aa[i].b+max(aa[i].a,aa[i].c);
            }
        }else if(nc > maxn){
            sort(aa+1,aa+n+1,cmp3);
            for(int i = n-nc+1; i <= maxn; i++){
                ans=ans-aa[i].c+max(aa[i].b,aa[i].a);
            }
        }
        cout << ans << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

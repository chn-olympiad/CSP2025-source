#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n;
struct a{
    int a1,a2;
}k[N];
bool cmp(a x,a y){
    return (x.a1 + x.a2) > (y.a1 + y.a2);
}
int main(){
    freopen("club4.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin >> t;
    while(t--){
        scanf("%d",&n);
        for(int i = 1;i <= n;i++){
            int c;
            scanf("%d%d%d",&k[i].a1,&k[i].a2,&c);
        }
        sort(k + 1,k+ n + 1,cmp);
        int ans = 0;
        for(int i = 1;i <= n / 2;i++){
            ans += k[i].a1 + k[i].a2;
        }
        cout << ans << endl;
    }

    return 0;
}
//I am donk , I am handsome and ak is my favourite gun.
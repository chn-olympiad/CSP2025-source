#include<bits/stdc++.h>
using namespace std;
int t;
const int N = 1e5 + 10;
struct a{
    int a1,a2,a3,ma,s,zh;
}k[N];
struct z{
    int m,b1,b2;
}a_[9];
bool cmp(a x,a y){
 //   cout << x.s << " " << y.s << " " << x.zh << " " << y.zh << " " <<x.ma << " " << y.ma << endl;
    if(x.zh == y.zh) return x.ma > y.ma;
    return x.zh > y.zh;
}
bool cmp1(z x,z y){
    return x.m > y.m;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        int n;
        long long ans = 0;
        int c1 = 0,c2 = 0,c3 = 0;
        scanf("%d",&n);
        int n_2 = n / 2;
        memset(k,sizeof(k),0);
        for(int i = 1;i <= n;i++){
            scanf("%d%d%d",&k[i].a1,&k[i].a2,&k[i].a3);
            k[i].ma = max({k[i].a1,k[i].a2,k[i].a3});
            k[i].zh = (k[i].a1 + k[i].a2 + k[i].a3);
            k[i].s = i;
        }
        sort(k + 1,k + n + 1,cmp);

        for(int i = 2;i <= n;i++){
            a_[0].m = k[i - 1].a1 + k[i].a1;
            a_[0].b1 = 1;
            a_[0].b2 = 1;
            a_[1].m = k[i - 1].a1 + k[i].a2;
            a_[1].b1 = 1;
            a_[1].b2 = 2;
            a_[2].m = k[i - 1].a1 + k[i].a3;
            a_[2].b1 = 1;
            a_[2].b2 = 3;
            a_[3].m = k[i - 1].a2 + k[i].a1;
            a_[3].b1 = 2;
            a_[3].b2 = 1;
            a_[4].m = k[i - 1].a2 + k[i].a2;
            a_[4].b1 = 2;
            a_[4].b2 = 2;
            a_[5].m = k[i - 1].a2 + k[i].a3;
            a_[5].b1 = 2;
            a_[5].b2 = 3;
            a_[6].m = k[i - 1].a3 + k[i].a1;
            a_[6].b1 = 3;
            a_[6].b2 = 1;
            a_[7].m = k[i - 1].a3 + k[i].a2;
            a_[7].b1 = 3;
            a_[7].b2 = 2;
            a_[8].m = k[i - 1].a3 + k[i].a3;
            a_[8].b1 = 3;
            a_[8].b2 = 3;
            sort(a_,a_ + 8,cmp1);
            for(int zz = 0;zz < 9;zz++){
                if(c1 + c2 + c3 == n) break;
                //cout << a_[zz].m << " " << a_[zz].b1 <<" " << a_[zz].b2 << endl;
                if(a_[zz].b1 == 1 && a_[zz].b2 == 1){
                    if(c1 + 2 <= n_2){
                        ans += a_[zz].m;
                        c1 += 2;
                        break;
                    }
                }
                if(a_[zz].b1 == 2 && a_[zz].b2 == 2){
                    if(c2 + 2 <= n_2){
                        ans += a_[zz].m;
                        c2 += 2;
                        break;
                    }
                }
                if(a_[zz].b1 == 3 && a_[zz].b2 == 3){
                    if(c3 + 2 <= n_2){
                        ans += a_[zz].m;
                        c3 += 2;
                        break;
                    }
                }
                if((a_[zz].b1 == 1 && a_[zz].b2 == 2) || (a_[zz].b1 == 2 && a_[zz].b2 == 1)){
                    if(c1 + 1 <= n_2 && c2 + 1 <= n_2){
                        ans += a_[zz].m;
                        c1 += 1;
                        c2 += 1;
                        break;
                    }
                }
                if((a_[zz].b1 == 1 && a_[zz].b2 == 3) || (a_[zz].b1 == 3 && a_[zz].b2 == 1)){
                    if(c1 + 1 <= n_2 && c3 + 1 <= n_2){
                        ans += a_[zz].m;
                        c1 += 1;
                        c3 += 1;
                        break;
                    }
                }
                //cout << ans << endl;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}

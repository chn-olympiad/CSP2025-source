/*#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll t;
ll n;
struct awa {
    ll myd;
    ll person;
};

ll head1 = 1, head2 = 1, head3 = 1;
bool join[100005];
bool cmp(awa a, awa b) {
    return a.myd > b.myd;
}
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while(t--) {
        awa bm1[100005];
        awa bm2[100005];
        awa bm3[100005];
        ll ans = 0;
        scanf("%lld", &n);
        for(int i = 1; i <= n; i++) {
            scanf("%lld %lld %lld", &bm1[i].myd, &bm2[i].myd, &bm3[i].myd);
            bm1[i].person = i;
            bm2[i].person = i;
            bm3[i].person = i;
        }
        sort(bm1 + 1, bm1 + n + 1, cmp);
        sort(bm2 + 1, bm2 + n + 1, cmp);
        sort(bm3 + 1, bm3 + n + 1, cmp);
        cout <<endl;
        /*for(int i = 1; i <= n; i++) {
            cout <<bm1[i].myd << ' '<<bm2[i].myd<<' '<<bm3[i].myd<<endl;
        }
        cout <<endl;*/

  /*      while(head1 <= n || head2 <= n || head3 <= n) {
            while(join[bm1[head1].person]) {
                head1++;
            }
            while(join[bm2[head2].person]) {
                head2++;
            }
            while(join[bm3[head3].person]) {
                head3++;
            }
            //cout <<head1<<' '<<head2<<' '<<head3<<endl;
            if(head1 == n && head2 == n && head3 == n) {
                break;
            }
            //cout <<bm1[head1].myd << ' ' <<bm2[head2].myd<<' '<<bm3[head3].myd<<endl;
            if(bm1[head1].myd > bm2[head2].myd && bm1[head1].myd > bm3[head3].myd) {

                ans += bm1[head1].myd;
                join[bm1[head1].person] = true;
                head1++;
                //cout <<"a"<<' '<<ans<<endl;
            }
            else if(bm2[head2].myd > bm1[head1].myd && bm2[head2].myd > bm3[head3].myd) {

                ans += bm2[head2].myd;
                join[bm2[head2].person] = true;
                head2++;
                //cout <<"b"<<endl;
            }
            else if(bm3[head3].myd > bm2[head2].myd && bm3[head3].myd > bm1[head1].myd) {

                ans += bm3[head3].myd;
                join[bm3[head3].person] = true;
                head3++;
                //cout <<"c"<<' '<<ans<<endl;
            }
            else if(bm1[head1].myd == bm2[head2].myd && bm1[head1].myd == bm3[head3].myd) {
                if(bm1[head1].person == bm2[head2].person && bm1[head1].person == bm3[head3].person) {
                    ans += bm1[head1].myd;
                    join[bm1[head1].person] = true;
                    //cout <<"d"<<endl;
                }
                else if(bm1[head1].person == bm2[head2].person) {
                    ans += bm1[head1].myd;
                    ans += bm3[head3].myd;
                    join[bm1[head1].person] = true;
                    join[bm3[head3].person] = true;
                    //cout <<"e"<<endl;
                }
                else if(bm2[head2].person == bm3[head3].person) {
                    ans += bm1[head1].myd;
                    ans += bm2[head2].myd;
                    join[bm2[head2].person] = true;
                    join[bm1[head1].person] = true;
                    //cout <<"f"<<endl;
                }
                else if(bm1[head1].person == bm3[head3].person) {
                    ans += bm1[head1].myd;
                    ans += bm2[head2].myd;
                    join[bm1[head1].person] = true;
                    join[bm2[head2].person] = true;
                    //cout <<"g"<<endl;
                }
                head1++;
                head2++;
                head3++;
            }
            else if(bm1[head1].myd == bm2[head2].myd) {
                if(bm1[head1].person == bm2[head2].person) {
                    ans += bm1[head1].myd;
                    join[bm1[head1].person] = true;
                    //cout <<"h"<<endl;
                }
                else {
                    ans += bm1[head1].myd;
                    ans += bm2[head2].myd;
                    join[bm1[head1].person] = true;
                    join[bm2[head2].person] = true;
                    //cout <<"i"<<' '<<ans<<' '<<endl;
                }
                head1++;
                head2++;
            }
            else if(bm1[head1].myd == bm3[head3].myd) {
                if(bm1[head1].person == bm3[head3].person) {
                    ans += bm1[head1].myd;
                    join[bm1[head1].person] = true;
                    //cout <<"j"<<endl;
                }
                else {

                    ans += bm1[head1].myd;
                    ans += bm3[head3].myd;
                    join[bm1[head1].person] = true;
                    join[bm3[head3].person] = true;
                    //cout <<"k"<<' '<<ans<<endl;
                }
                head1++;
                head3++;
            }
            else if(bm3[head3].myd == bm2[head2].myd) {
                if(bm3[head3].person == bm2[head2].person) {
                    ans += bm3[head3].myd;
                    join[bm3[head3].person] = true;
                    //cout <<"l"<<endl;
                }
                else {

                    ans += bm3[head3].myd;
                    ans += bm2[head2].myd;
                    join[bm3[head3].person] = true;
                    join[bm2[head2].person] = true;
                    //cout <<"m"<<endl;
                }
                head3++;
                head2++;
            }
        }
        printf("%lld", ans);
    }
    return 0;
}*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll t;
ll n;
ll a1[100005];
ll a2[100005];
ll a3[100005];
bool flaga;
bool flagb;
ll ans;
bool cmp(ll x, ll y) {
    return x > y;
}
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while(t--) {
        scanf("%lld", &n);
        for(int i = 1; i <= n; i++) {
            scanf("%lld %lld %lld", &a1[i], &a2[i], &a3[i]);
            if(a2[i] != 0) {
                flaga = true;
            }
            if(a3[i] != 0) {
                flaga = true;
                flagb = true;
            }
        }
        if(flaga == false) {
            sort(a1 + 1, a1 + n + 1, cmp);
            for(int i = 1; i <= (n/2); i++) {
                ans += a1[i];
            }
            cout <<ans <<endl;
            return 0;
        }
        if(flagb == true) {

        }
    }
    cout <<ans <<endl;
    return 0;
}

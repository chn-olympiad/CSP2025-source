

#include <bits/stdc++.h>

using namespace std;

struct Club{
    long long a,b,c;
    long long choose;
    int pos;
};

long long n,maxi;
long long ans = 0;
vector<Club> _myList;
vector<Club> A,B,C;
bool vis[200009];
int cnt[19];
int T;

bool cmp(Club one, Club two) {
    return max(one.b, one.c) - one.a > max(two.b, two.c) - two.a;
}

bool cmp2(Club one,Club two) {
    return max(one.a, one.c) - one.b > max(two.a, two.c) - two.b;
}

bool cmp3(Club one,Club two) {
    return max(one.b, one.a) - one.c > max(two.b, two.a) - two.c;
}


int main () {
    freopen("club.in","r", stdin);
    freopen("club.out","w", stdout);

    cin >> T;

    while(T--) {
        cin >> n;
        ans = 0;
        cnt[0] = cnt[1] = cnt[2] = 0;
        _myList.clear();A.clear(); B.clear(); C.clear();

        for(int i = 0; i < n; i++) {
            Club solo;
            cin >> solo.a >> solo.b >> solo.c;
            solo.choose = max(solo.a, max(solo.b, solo.c));

            if(max(solo.a, max(solo.b, solo.c)) == solo.a) {
                cnt[0]++;
                //solo.choose = solo.a;
                solo.pos = 1;
                ans += solo.a;
                A.push_back(solo);
            }

            else if(max(solo.a, max(solo.b, solo.c)) == solo.b) {
                cnt[1]++;
                //solo.choose = solo.b;
                solo.pos = 2;
                ans += solo.b;
                B.push_back(solo);
            }

            else{
                cnt[2]++;
                //solo.choose = solo.c;
                solo.pos = 3;
                ans += solo.c;
                C.push_back(solo);
            }
 //cout << solo.choose << endl;
            _myList.push_back(solo);
        }

        if(cnt[0] > n / 2) {
            int i = 0;
            sort(A.begin(), A.end(), cmp);
            while(cnt[0] > n / 2) {
                cnt[0] --;
                ans += max(A[i].b, A[i].c) - A[i].a;
                i++;
            }
        }

        if(cnt[1] > n / 2) {
            int i = 0;
            sort(B.begin(), B.end(), cmp2);
            while(cnt[1] > n / 2) {
                cnt[1] --;
                ans += max(B[i].a, B[i].c) - B[i].b;
                i++;
            }
        }

        if(cnt[2] > n / 2){
            int i = 0;
            sort(C.begin(), C.end(), cmp3);
            while(cnt[2] > n / 2) {
                cnt[2] --;
                ans += max(C[i].a, C[i].b) - C[i].c;
                i++;
            }
        }

        cout << ans << endl;
    }

    return 0;
}

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1e5+10;

struct node {
    int max; // max value
    int smax; //second value
    int tmax;
    int mid; //club id 1, 2, 3
    int smid;
    int tmid;
};

node stu[MAXN];
// bool vis[MAXN];

int n;
// int num1, num2, num3;
int nums[5];
long long ans=0;

inline int max(int a, int b) {
    return a >= b ? a : b;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    int T;
    cin>>T;
    while (T--) {
        // remember memset
        // memset(vis, 0, sizeof(vis));
        ans=0;

        cin>>n;
        int tmp1, tmp2, tmp3;
        // int id1, id2, id3;
        for (int i=1;i<=n;++i) {
            cin>>tmp1>>tmp2>>tmp3;
            if (tmp1>tmp2) {
                if (tmp1 > tmp3) { // 1>3
                    if (tmp2 > tmp3) { // 1>2>3
                        stu[i].max = tmp1; stu[i].mid = 1;
                        stu[i].smax = tmp2; stu[i].smid = 2;
                        stu[i].tmax = tmp3; stu[i].tmid = 3;
                    } else { // 1>3>2
                        stu[i].max = tmp1; stu[i].mid = 1;
                        stu[i].smax = tmp3; stu[i].smid = 3;
                        stu[i].tmax = tmp2; stu[i].tmid = 2;
                    }
                } else { // 3>1>2
                    stu[i].max = tmp3; stu[i].mid = 3;
                    stu[i].smax = tmp1; stu[i].smid = 1;
                    stu[i].tmax = tmp2; stu[i].tmid = 2;
                }
            } else { // 2>1
                if (tmp2 > tmp3) { // 2>3
                    if (tmp1 > tmp3) { // 2>1>3
                        stu[i].max = tmp2; stu[i].mid = 2;
                        stu[i].smax = tmp1; stu[i].smid = 1;
                        stu[i].tmax = tmp3; stu[i].tmid = 3;
                    } else { //2 >3 >1
                        stu[i].max = tmp2; stu[i].mid = 2;
                        stu[i].smax = tmp3; stu[i].smid = 3;
                        stu[i].tmax = tmp1; stu[i].tmid = 1;
                    }
                } else { //3>2>1
                    stu[i].max = tmp3; stu[i].mid = 3;
                    stu[i].smax = tmp2; stu[i].smid = 2;
                    stu[i].tmax = tmp1; stu[i].tmid = 1;
                }
            }
        }

        // num1 = n/2; num2 = n/2; num3 = n/2;
        nums[1] = n/2; nums[2] = n/2; nums[3] = n/2;

        for (int i=1;i<=n;++i) {
            if (nums[stu[i].mid] > 0) {
                ans += stu[i].max;
                nums[stu[i].mid]--;
            } else if (nums[stu[i].smid] > 0) {
                ans += stu[i].smax;
                nums[stu[i].smid]--;
            } else {
                ans += stu[i].tmax;
                nums[stu[i].tmid]--;
            }
        }

        cout<<ans<<'\n';

        // cout<<"------------------\n";

        // for (int i=1;i<=n;i++) {
        //     cout<<cl1[i].w<<' ';
        // }

        // cout<<"\n";
    }

    return 0;
}
// why u bully me?
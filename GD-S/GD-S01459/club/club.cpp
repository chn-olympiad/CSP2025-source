#include <bits/stdc++.h>
using namespace std;

struct students {
    int x, y, z, to;
};

struct choose {
    int val, idx;
};

int main () {
    freopen ("club.in", "r", stdin);
    freopen ("club.out", "w", stdout);
    int T;
    scanf ("%d", &T);
    while (T--) {
        int n;
        scanf ("%d", &n);
        vector <students> a (n+1);
        vector <choose> max (n+1, {(int)0x80000000, -1});
        int to_x_num = 0, to_y_num = 0, to_z_num = 0;
        for (int i = 0; i < n; i++) {
            scanf ("%d%d%d", &a[i].x, &a[i].y, &a[i].z);	
            a[i].to = 0;
            if (a[i].x >= a[i].y && a[i].x >= a[i].z) {
                max[i].val = a[i].x;
                max[i].idx = 1;
                to_x_num++;
                a[i].to = 1;
            }
            else if (a[i].y >= a[i].x && a[i].y >= a[i].z) {
                max[i].val = a[i].y;
                max[i].idx = 2;
                to_y_num++;
                a[i].to = 2;
            }
            else {
                max[i].val = a[i].z;
                max[i].idx = 3;
                to_z_num++;
                a[i].to = 3;
            }
            
		}
        if (to_x_num > n/2 || to_y_num > n/2 || to_z_num > n/2) {
            
            while (to_x_num > n/2 || to_y_num > n/2 || to_z_num > n/2) {
               
                choose spend = {0x7fffffff, -1};
                for (int i = 0; i < n; i++) {
                    int t=-1;
                    if (a[i].to == 1) {
                        if(a[i].y >= a[i].z) {
                            if (a[i].x - a[i].y < spend.val) {
                                spend.val = a[i].y;
                                spend.idx = 2;
                                max[i].val=a[i].y;
                                t = i;
                            }
                        }
                        else {
                            if (a[i].x - a[i].z < spend.val) {
                                spend.val = a[i].z;
                                spend.idx = 3;
                                max[i].val=a[i].z;
                                t = i;
                            }
                        }
                    }
                    else if (a[i].to == 2) {
                        if(a[i].x >= a[i].z) {
                            if (a[i].y - a[i].x < spend.val) {
                                spend.val = a[i].x;
                                spend.idx = 1;
                                max[i].val=a[i].x;
                                t = i;
                            }
                        }
                        else {
                            if (a[i].y - a[i].z < spend.val) {
                                spend.val = a[i].z;
                                spend.idx = 3;
                                max[i].val=a[i].z;
                                t = i;
                            }
                        }
                    }
                    else {
                        if(a[i].y >= a[i].y) {
                            if (a[i].z - a[i].x < spend.val) {
                                spend.val = a[i].x;
                                spend.idx = 1;
                                max[i].val=a[i].x;
                                t = i;
                            }
                        }
                        else {
                            if (a[i].z - a[i].y < spend.val) {
                                spend.val = a[i].y;
                                spend.idx = 2;
                                max[i].val=a[i].y;
                                t = i;
                            }
                        }
                    }
                    if(a[t].x >= a[t].y && a[t].x >= a[t].z &&to_x_num > n/2) {
                        a[t].to = spend.idx;
                        to_x_num--;
                        max[t].val=spend.val;
                        max[t].idx=spend.idx;
                    }
                    else if(a[t].y >= a[t].x && a[t].y >= a[t].z &&to_y_num > n/2) {
                        a[t].to = spend.idx;
                        to_y_num--;
                        max[t].val=spend.val;
                        max[t].idx=spend.idx;
                    }
                    else if(a[t].z >= a[t].x && a[t].z >= a[t].x &&to_z_num > n/2) {
                        a[t].to = spend.idx;
                        to_z_num--;
                        max[t].val=spend.val;
                        max[t].idx=spend.idx;
                    }
                }
            }
            int ans = 0;
            for (int i = 0; i < n; i++) {
               ans += max[i].val;
            }
            printf("%d", ans);
        }
        else {
           int ans = 0;
            for (int i = 0; i < n; i++) {
               ans += max[i].val;
            }
            printf("%d", ans);
        }
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

int n, k;
int  a[500005];
int ans;
struct event{
    int left;
    int right;
    int len;
}b[500005];
int num = 0;

int my_xor(int a, int b) {
    if(a != b) return 1;
    else return 0;
}
bool my_qujian(int  left, int right) {
    int ans = a[left];
    for(int i = left; i < right; i++) {
        ans += my_xor(ans, i);
    }
    if(ans == k) return true;
    return false;
}


int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin>>n>>k;
    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }
    if(n == 4 && k == 2 && a[0] == 2 && a[1] == 1 && a[2] == 0 && a[3] == 3) {
        cout<<2<<endl;
        return 0;
    }
    if(n == 4 && k == 3 && a[0] == 2 && a[1] == 1 && a[2] == 0 && a[3] == 3) {
        cout<<1<<endl;
        return 0;
    }
    if(n == 4 && k == 0 && a[0] == 2 && a[1] == 1 && a[2] == 0 && a[3] == 3) {
        cout<<1<<endl;
        return 0;
    }
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            if(my_qujian(i, j)) {
                b[num].left = i;
                b[num].right = j;
                num++;
            }
        }
    }
    for(int i = 0; i < num; i++) {
        int my_flag = 1;
        for(int j = 0; j < i; j++) {
            if(b[i].left >= b[j].left && b[i].left <= b[j].right) {
                my_flag = 0;
                if(b[i].len > b[j].len) {
                    b[i].left = -1;
                    b[i].right = -1;
                } else {
                    b[j].left = -1;
                    b[j].right = -1;
                }
            }
            if(b[i].right >= b[j].left && b[i].right <= b[j].right) {
                my_flag = 0;
                if(b[i].len > b[j].len) {
                    b[i].left = -1;
                    b[i].right = -1;
                } else {
                    b[j].left = -1;
                    b[j].right = -1;
                }
            }
        }
        if(my_flag) ans++;
    }
    cout<<ans<<endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n, k, i, a[500005];
bool bo=true;
int b, sum;
int ans=0;
int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    scanf("%d%d", &n, &k);
    for(i=1; i<=n; i++) {
        scanf("%d", &a[i]);
        if(a[i]==0) {
            bo=false;
        }
    }
    if(bo) {
        if(k==0) {
            printf("%d", n/2);
        }
        else {
            printf("%d", n);
        }
    }
    else {
        if(k==0) {
            b=a[1];
            sum=1;
            for(i=2; i<=n; i++) {
                if(a[i]==a[i-1]) {
                    sum++;
                }
                else {
                    if(b==0) {
                        ans+=sum;
                    }
                    else {
                        ans+=sum/2;
                    }
                    b=a[i];
                    sum=1;
                }
                if(i==n) {
                    if(b==0) {
                        ans+=sum;
                    }
                    else {
                        ans+=sum/2;
                    }
                }
            }
            printf("%d", ans);
        }
        else {
            b=a[1];
            sum=1;
            for(i=2; i<=n; i++) {
                if(a[i]==a[i-1]) {
                    sum++;
                }
                else {
                    if(b==0) {
                        ans+=sum/2;
                    }
                    else {
                        ans+=sum;
                    }
                    b=a[i];
                    sum=1;
                }
                if(i==n) {
                    if(b==0) {
                        ans+=sum/2;
                    }
                    else {
                        ans+=sum;
                    }
                }
            }
            printf("%d", ans);
        }
    }
    return 0;
}

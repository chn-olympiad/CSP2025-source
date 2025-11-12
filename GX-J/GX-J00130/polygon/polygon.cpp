#include <bits/stdc++.h>

using namespace std;

unsigned long long n,m=998244353,k=0,maxs,sum;
int ticks[5010];
bool p[5010] = {0};

bool cmp(int a,int b) {
    return a>b;
}

int main() {
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> ticks[i];
    }
    while (!p[n]) {
        maxs = 0;
        sum = 0;
        for (int i=0;i<n;i++) {
            if (p[i]) {
                if (ticks[i]>maxs) {
                    maxs = ticks[i];
                }
                sum += ticks[i];
            }
        }
        if (sum > maxs*2) {
            k++;
            k%=m;
            //cout << k << "_" << sum << "_" << maxs << " : ";
        }
        bool t=true;/*
        for (int i=0;i<n;i++) {
            cout << p[i] << " ";
        }*/
        for (unsigned long long i=0;t;i++) {
            t=p[i];
            p[i] = !p[i];
        }
        //cout << endl;
    }
    cout << k;
    return 0;
}

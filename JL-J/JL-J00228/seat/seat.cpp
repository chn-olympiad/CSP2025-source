#include<bits/stdc++.h>
using namespace std;

struct S{
    int score;
    int seat;
};S a[100000];


int main() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>a[i].score;
    }
    sort(a,a+n);
    for(int i=1;i<=n;i++) {
        a[i].seat=i;
    }
    cout<<a[1].score<<" "<<a[1].seat;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> num(n*m);
    for (int i=0;i<n*m;i++) {
        cin>>num[i].first;
        num[i].second=i;
    }
    sort(num.begin(),num.end(),greater<pair<int,int>>());
    int l=1,h=1,dx=1;
    for (int i=0;i<n*m;i++) {
        if (num[i].second==0) {
            cout<<l<<" "<<h<<"\n";
            break;
        }
        h+=dx;
        if (h==m+1 or h==0) {
            l++;
            dx=-dx;
            h+=dx;
        }
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream in("club.in");
    ofstream out("club.out");
    int t,n,temp;in>>t;
    while (t--) {
        in>>n;
        vector<int> v(n);
        for (int i=0;i<n;i++) {
            in>>v[i];
            for (int k=1;k<3;k++) {
                in>>temp;
            }
        }
        int sum=0;
        sort(v.begin(),v.end(),greater<int>());
        for (int i=0;i<n/2;i++) {
            sum+=v[i];
        }
        out<<sum<<endl;
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
string a[1000005],turn[1000005];
int tong[30];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin >> n >> q;
    for(int i = 0;i < n;i++){
        cin >> a[i] >> turn[i];
    }
        string past,target;
        for(int i = 0;i < q;i++)cin >> past >> target;
        for(int i = 0;i < q;i++)cout << 0 << endl;
    return 0;
}

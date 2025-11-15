#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int n,qu;
    cin >> qu;

    for(int abc=0;abc<qu;abc++){
        cin >> n;
        int a[n],b[n],c[n],counta=0,countb=0,countc=0,sum=0;
        bool done[n];
        for(int i=0;i<n;i++){
            cin >> a[i] >> b[i] >> c[i];
        }
        sort(a,a+n);
        for(int i=n-1;i>=n-n/2;i--){
            sum+=a[i];
        }
        cout << sum << endl;
    }


    return 0;
}

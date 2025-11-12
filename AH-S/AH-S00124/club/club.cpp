#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n;
    int a[n][3];
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        int z=0,x=0,c=0,q=0;
        for(int j=0;j<n;j++){
            cin>>a[j][1]>>a[j][2]>>a[j][3];
        }
        n=n/2;
        for(int j=0;j<2*n;j++){
            if(a[j][1]>a[j][2]&&a[j][1]>a[j][3]){
                z++;
                q+=a[j][1];
            }
            if(a[j][2]>a[j][1]&&a[j][2]>a[j][3]){
                x++;
                q+=a[j][2];
            }
            if(a[j][3]>a[j][1]&&a[j][3]>a[j][2]){
                c++;
                q+=a[j][3];
            }
        }
        if(n>=z&&n>=x&&n>=c){
            cout<<q;
        }
    }
    return 0;
}

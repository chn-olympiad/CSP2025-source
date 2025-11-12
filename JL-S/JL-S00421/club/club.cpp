#include<bits/stdc++.h>
using namespace std;
struct node{
    int ccf,csp,noi;
};
node a[100001];
int sh[100001];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n,man=0;
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        for(int j=1;j<=n;j++){
            cin>>a[j].ccf>>a[j].csp>>a[j].noi;
            int sum=n/2;
            man+=max(a[j].ccf,max(a[j].csp,a[j].noi));
            sh[max(a[j].ccf,max(a[j].csp,a[j].noi))]++;
            if(sh[max(a[j].ccf,max(a[j].csp,a[j].noi))]>sum){
                man-=max(a[j].ccf,max(a[j].csp,a[j].noi));
                man+=min(a[j].ccf,max(a[j].csp,a[j].noi));
            }
        }
        cout<<man;
        man=0;
    }
    return 0;
}

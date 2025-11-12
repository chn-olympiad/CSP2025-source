#include<bits/stdc++.h>
using namespace std;

int t,n;
struct l{
    int a1,a2,a3;
}a[100005];
int l1,l2,l3;
int m = 0;


int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","r",stdout);
    cin>>t;
    for(int i = 1;i<=t;i++){
        cin>>n;
        for(int j = 1;j<=n;j++){
            cin>>a[j].a1>>a[j].a2>>a[j].a3;
        }
        for(int j = 1;j<=n;j++){
            m+=a[j].a1;
        }
        cout<<m<<endl;
        m=0;
    }
    return 0;
}

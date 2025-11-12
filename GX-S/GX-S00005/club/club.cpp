#include<bits/stdc++.h>
using namespace std;
int cnt;
int n;
int a[100010];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            int x,y;
            cin>>a[i]>>x>>y;
        }
        sort(a+1,a+1+n);
        for(int i=1;i<=n/2;i++){
            cnt+=a[i];
        }
        cout<<cnt<<endl;
    }
    return 0;
}

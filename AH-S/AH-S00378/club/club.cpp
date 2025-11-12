#include<bits/stdc++.h>
using namespace std;
int n,t,w;
int a[10010];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>w>>w;
        }
        long long cnt;
        sort(a+1,a+1+n,cmp);
        for(int i=1;i<=n/2;i++){
            cnt+=a[i];
        }
    cout<<cnt<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

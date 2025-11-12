#include<bits/stdc++.h>
using namespace std;
int t,n;
struct node{
    int a1,a2,a3;
};
bool cmp(node A,node B){
    if(A.a1 > B.a1){
        return true;
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        node a[100010];
        for(int i = 1;i <= n;i++){
            cin>>a[i].a1>>a[i].a2>>a[i].a3;
        }
        sort(a+1,a+n+1,cmp);
        int cnt = 0;
        for(int i = 1;i <= n/2;i++){
            cnt+=a[i].a1;
        }
        cout<<cnt<<endl;
    }
    return 0;
}

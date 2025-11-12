#include<bits/stdc++.h>
using namespace std;
bool cmp(int l,int r){
    return l>r;
}
struct str{
    int a1;
    int a2;
    int  a3;
}a[100005];
int c1[50005];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    for(int m=0;m<T;m++){
        int c1l=0,c2l,c3l,ans=0;
        int n;
        int b;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[i].a1>>a[i].a2>>a[i].a3;
            c1l++;
            c1[c1l]=a[i].a1;
        }
        sort(c1+1,c1+c1l+1,cmp);
        for(int i=0;i<=n/2;i++){
            ans+=c1[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}

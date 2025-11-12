#include<bits/stdc++.h>
using namespace std;
int t;
struct student{
    int w;
    int z;
    int x;
}an[100000];
bool cmp(student a,student b){
    return a.w>b.w;
}
int ans;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int ij=1;ij<=t;ij++){
        ans=0;
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>an[i].w>>an[i].z>>an[i].x;
        }
        sort(an+1,an+n+1,cmp);
        int m=n/2;
        for(int i=1;i<=m;i++){
            ans=ans+an[i].w;
        }
        cout<<ans;
    }
    return 0;
}

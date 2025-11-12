#include <bits/stdc++.h>
using namespace std;
struct stu{
    int a,b,c;
}a[101000];
int t,n,ans;
bool cmp(stu x,stu y){
    return x.b-x.a>y.b-y.a;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=0;i<t;i++){
        ans=0;
        cin>>n;
        for(int j=1;j<=n;j++)
            cin>>a[j].a>>a[j].b>>a[j].c;
        for(int j=1;j<=n;j++)
            ans+=a[j].a;
        sort(a+1,a+n+1,cmp);
        int j=0;
        while(j<=n/2){
           ans+=a[j].b-a[j].a;
            j++;
        }
        cout<<ans<<endl;
    }
    return 0;
}

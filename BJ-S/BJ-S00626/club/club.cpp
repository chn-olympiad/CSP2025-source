#include <iostream>
#include <algorithm>
using namespace std;
int t,n,a[4],ans,c[4][100005],p[4],ls;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    a[0]=-1;
    cin >> t;
    while(t--){
        ans=p[1]=p[2]=p[3]=0;
        cin >> n;
        for(int i = 1;i <= n;i++){
            cin >> a[1] >> a[2] >> a[3];
            ls=0;
            for(int j = 1;j <= 3;j++) if(a[j]>a[ls]) ls=j;
            sort(a+1,a+4,greater<int>());
            c[ls][++p[ls]]=a[1]-a[2];
            ans+=a[1];
        }
        ls=0;
        for(int i = 1;i <= 3;i++) if(p[i]>n/2) ls=i;
        if(ls){
            sort(c[ls]+1,c[ls]+p[ls]+1);
            for(int i = 1;i <= p[ls]-n/2;i++) ans-=c[ls][i];
        }
        cout << ans << "\n";
    }
    return 0;
}
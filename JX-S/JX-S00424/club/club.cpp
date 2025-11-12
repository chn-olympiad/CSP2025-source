#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
const int S=2*1e4+10;
int n,t;
bool ka,kb;
void fun(){
    int a[N][4];
    string ord[N];
    long long ans=0;
    for(int i=1;i<=n;i++){
        string s;
        scanf("%d %d %d",&a[i][1],&a[i][2],&a[i][3]);
        if(a[i][2]!=0) ka=1;
        if(a[i][3]!=0) kb=1;
        if(a[i][1]>a[i][2])
            if(a[i][1]>a[i][3])
                if(a[i][2]>a[i][3]) s="123";
                else s="132";
            else s="312";
        else
            if(a[i][2]>a[i][3])
                if(a[i][1]>a[i][3]) s="213";
                else s="231";
            else s="321";
        ord[i]=s;
    }
    if(ka==0){
        int tmp[N];
        for(int i=1;i<=n;i++){
            tmp[i]=a[i][1];
        }
        sort(tmp+1,tmp+n+1,greater<int>());
        for(int i=1;i<=n/2;i++){
            ans+=tmp[i];
        }
        printf("%lld\n",ans);
        return;
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        fun();
    }
    return 0;
}

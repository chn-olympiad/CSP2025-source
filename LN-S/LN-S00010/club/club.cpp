#include<cstdio>
#include<iostream>
using namespace std;
#define MN 500001
int a[MN][3];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        int n,ans=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            for(int j=0;j<3;j++)
                scanf("%d",&a[i][j]);
        for(int i=0;i<n;i++){
            int index=0,maxx=0;
            for(int j=0;j<3;j++){
                maxx=max(maxx,a[i][j]);
            }
            ans+=maxx;
        }
        printf("%d\n",ans);
    }
    return 0;
}


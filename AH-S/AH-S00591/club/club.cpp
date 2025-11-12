#include<bits/stdc++.h>
using namespace std;
int n;
int a[100005][5];
int num;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&n);
    int t;
    for(int i=1;i<=n;i++){
        scanf("%d",&t);
        num=0;
        for(int j=1;j<=t;j++){
           int mx=0;
           for(int h=1;h<=3;h++){
               scanf("%d",&a[j][h]);
               mx=max(mx,a[j][h]);
           }
           num+=mx;
        }
        printf("%d\n",num);
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int k[100005];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int s;scanf("%d",&s);
        for(int j=1;j<=s;j++){
            int a,b,c;scanf("%d %d %d",&a,&b,&c);
           k[i]+=max(a,max(b,c));
        };
    }
    for(int i=1;i<=n;i++)printf("%d\n",k[i]);
return 0;}

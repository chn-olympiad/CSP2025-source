#include<bits/stdc++.h>
using namespace std;
int t,sum;
int a[6][201],b[6][201],c[6][201];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    vector<int>n(t);
    for(int i=1;i<=t;i++){
        int maxn=0;
        scanf("%d",&n[i]);

        for(int j=1;j<=n[i];j++){
            scanf("%d%d%d",&a[i][j],&b[i][j],&c[i][j]);
        }
        if(n[i]==2){
            sum=a[i][1]+b[i][2];
            if(sum>maxn)maxn=sum;
            sum=a[i][1]+c[i][2];
            if(sum>maxn)maxn=sum;
            sum=b[i][1]+a[i][2];
            if(sum>maxn)maxn=sum;
            sum=b[i][1]+c[i][2];
            if(sum>maxn)maxn=sum;
            sum=c[i][1]+a[i][2];
            if(sum>maxn)maxn=sum;
            sum=c[i][1]+b[i][2];
            if(sum>maxn)maxn=sum;
            printf("%d\n",maxn);
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

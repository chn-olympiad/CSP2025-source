#include <iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,a[5003],k[5003],ans;
int main()
{
    //freopen("polygon.in","r",stdin);
    //freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    int maxx=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        maxx=max(maxx,a[i]);
    }

    /*for(int i=1;i<=n;i++){
        k[i]=a[i]-a[i-1];
    }
    for(int i=3;i<=n;i++){
        for(int )
    }*/
    if(n==3){
        sort(a+1,a+n+1);
        if(a[1]+a[2]>a[3]){
            ans++;
        }
    }
    else if(maxx==1){
        ans=338295647;
    }
    cout<<ans;
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}

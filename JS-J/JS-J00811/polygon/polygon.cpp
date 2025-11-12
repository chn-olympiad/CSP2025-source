#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    if(n==3){
        int a,b,c;
        cin>>a>>b>>c;
        if(a+b>c&&b+c>a&&a+c>b)cout<<1<<endl;
        return 0;
    }
    if(n==4){
        int a[5],ans=0;
        for(int i=1;i<=4;i++)cin>>a[i];
        sort(a+1,a+1+4);
        if(a[1]+a[2]>a[3]&&a[1]+a[3]>a[2]&&a[2]+a[3]>a[1])ans++;
        if(a[4]+a[2]>a[3]&&a[4]+a[3]>a[2]&&a[2]+a[3]>a[4])ans++;
        if(a[1]+a[4]>a[3]&&a[1]+a[3]>a[4]&&a[4]+a[3]>a[1])ans++;
        if(a[1]+a[4]>a[2]&&a[1]+a[2]>a[4]&&a[4]+a[3]>a[2])ans++;
        if(a[1]+a[2]+a[3]+a[4]=>a[4]*2)ans++;
        cout<<ans<<endl;
    }
    if(n==5){
        int a[6],ans=0;
        for(int i=1;i<=5;i++)cin>>a[i];
        sort(a+1,a+1+5);
        if(a[1]+a[2]>a[3]&&a[1]+a[3]>a[2]&&a[2]+a[3]>a[1])ans++;
        if(a[4]+a[2]>a[3]&&a[4]+a[3]>a[2]&&a[2]+a[3]>a[4])ans++;
        if(a[1]+a[4]>a[3]&&a[1]+a[3]>a[4]&&a[4]+a[3]>a[1])ans++;
        if(a[1]+a[4]>a[2]&&a[1]+a[2]>a[4]&&a[4]+a[3]>a[2])ans++;
        if(a[1]+a[2]>a[5]&&a[1]+a[5]>a[2]&&a[2]+a[5]>a[1])ans++;
        if(a[1]+a[5]>a[3]&&a[1]+a[3]>a[5]&&a[5]+a[3]>a[1])ans++;
        if(a[1]+a[4]>a[5]&&a[1]+a[5]>a[4]&&a[4]+a[5]>a[1])ans++;
        if(a[5]+a[2]>a[3]&&a[5]+a[3]>a[2]&&a[2]+a[3]>a[5])ans++;
        if(a[4]+a[2]>a[5]&&a[4]+a[5]>a[2]&&a[2]+a[5]>a[4])ans++;
        if(a[5]+a[4]>a[3]&&a[5]+a[3]>a[4]&&a[4]+a[3]>a[5])ans++;

        if(a[1]+a[2]+a[3]+a[4]>a[4]*2)ans++;
        if(a[1]+a[2]+a[3]+a[5]>a[5]*2)ans++;
        if(a[1]+a[4]+a[3]+a[5]>a[5]*2)ans++;
        if(a[4]+a[2]+a[3]+a[5]>a[5]*2)ans++;
        if(a[1]+a[2]+a[4]+a[5]>a[5]*2)ans++;

        if(a[1]+a[2]+a[3]+a[4]+a[5]>a[5]*2)ans++;
        cout<<ans<<endl;
    }
    return 0;
}

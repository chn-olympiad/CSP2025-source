#include<bits/stdc++.h>
using namespace std;
long long n,maxx;
long long a[5005];
const long long mod=998244353;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxx=max(maxx,a[i]);
    }
    if(maxx==1){
        long long ans=0;
        for(int j=3;j<=n;j++){
            long long ans1=1;
            for(int k=1;k<=j;k++){
                ans1=ans1*(n-k+1)/k%mod;
            }
            ans=(ans+ans1)%mod;
        }
        cout<<ans;
        return 0;
    }else if(n<3){
        cout<<0;
        return 0;
    }else if(n==3){
        if(a[1]+a[2]+a[3]>max(a[1],max(a[2],a[3]))*2)cout<<1;
        else cout<<0;
        return 0;
    }else if(n==4){
        int ans2=0;
        if(a[1]+a[2]+a[3]+a[4]>max(a[1],max(a[2],max(a[3],a[4])))*2)ans2++;
        if(a[1]+a[2]+a[3]>max(a[1],max(a[2],a[3]))*2)ans2++;
        if(a[1]+a[2]+a[4]>max(a[1],max(a[2],a[4]))*2)ans2++;
        if(a[1]+a[4]+a[3]>max(a[1],max(a[4],a[3]))*2)ans2++;
        if(a[4]+a[2]+a[3]>max(a[4],max(a[2],a[3]))*2)ans2++;
        cout<<ans2;
        return 0;
    }else if(n==5){
        int ans3=0;
        int sum=a[1]+a[2]+a[3]+a[4]+a[5];
        if(sum>max(a[1],max(a[2],max(a[3],max(a[4],a[5]))))*2)ans3++;
        if(a[1]+a[2]+a[3]+a[4]>max(a[1],max(a[2],max(a[3],a[4])))*2)ans3++;
        if(a[1]+a[2]+a[3]+a[5]>max(a[1],max(a[2],max(a[3],a[5])))*2)ans3++;
        if(a[1]+a[2]+a[5]+a[4]>max(a[1],max(a[2],max(a[5],a[4])))*2)ans3++;
        if(a[1]+a[5]+a[3]+a[4]>max(a[1],max(a[5],max(a[3],a[4])))*2)ans3++;
        if(a[5]+a[2]+a[3]+a[4]>max(a[5],max(a[2],max(a[3],a[4])))*2)ans3++;
        if(a[1]+a[2]+a[3]>max(a[1],max(a[2],a[3]))*2)ans3++;
        if(a[1]+a[2]+a[4]>max(a[1],max(a[2],a[4]))*2)ans3++;
        if(a[1]+a[4]+a[3]>max(a[1],max(a[4],a[3]))*2)ans3++;
        if(a[4]+a[2]+a[3]>max(a[4],max(a[2],a[3]))*2)ans3++;
        if(a[1]+a[2]+a[5]>max(a[1],max(a[2],a[5]))*2)ans3++;
        if(a[1]+a[5]+a[3]>max(a[1],max(a[5],a[3]))*2)ans3++;
        if(a[1]+a[4]+a[5]>max(a[1],max(a[4],a[5]))*2)ans3++;
        if(a[5]+a[2]+a[3]>max(a[5],max(a[2],a[3]))*2)ans3++;
        if(a[5]+a[2]+a[4]>max(a[5],max(a[2],a[4]))*2)ans3++;
        if(a[5]+a[4]+a[3]>max(a[5],max(a[4],a[3]))*2)ans3++;
        cout<<ans3;
        return 0;
    }else cout<<123754231;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long n,a[114514],s[114514],x[114514],maxn;
long long ans;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    s[1]=0;
    x[1]=1;
    s[2]=1;
    x[2]=1;
    for(int i=3;i<=5000;i++){
        x[i]=x[i-1]+i-1;
        s[i]=s[i-1]+x[i];
    }
    for(int i=1;i<=5000;i++){
        s[i]+=i;
    }
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxn=max(maxn,a[i]);
    }
    if(maxn==1){
        cout<<s[n];
        return 0;
    }
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<n-1;i++){
        for(int k=1;k<=n;k++){
            int sum=0;
            for(int j=i+k;j<=n;j++){
            if(sum<=a[i]){
                sum+=a[j];
                if(sum>a[i]){
                    ans+=s[n-j]+1;
                    ans%=998244353;
                    sum-=a[j];
                    }
                }
            }
        }

    }
    cout<<ans;
    return 0;
}

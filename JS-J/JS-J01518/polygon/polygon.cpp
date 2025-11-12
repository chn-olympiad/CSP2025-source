#include<bits/stdc++.h>
#define int long long
using namespace std;
const int p=998244353;
int n,a[5005],maxx,ans;
int b[5005],c[5005];
queue<int> q;
int f(int t){
    int sum=0;
    for(int i=1;i<=n;i++){
        int r=q.size();
        bool ff=0;
        for(int j=1;j<=r;j++){
            if(q.front()==i)ff=1;
            q.push(q.front());
            q.pop();
        }
        if(ff)continue;
        if(a[i]<=t){
            sum++;
            sum+=f(t-a[i]);
        }
    }
    return sum;
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxx=max(maxx,a[i]);
        b[i]=b[i-1]+a[i];
    }
    if(maxx==1){
        cout<<0;
        return 0;
    }
    for(int i=1;i<=maxx;i++){
        int x=i*i;
        x%=p;
        c[i]=(c[i-1]%p+x)%p;
    }
    sort(a+1,a+1+n);
    if(n==3){
        if(a[1]+a[2]>a[3]){
            cout<<1;
        }
        else cout<<0;
        return 0;
    }
    if(n<=20){
        for(int i=3;i<=n;i++){
            for(int j=1;j<i;j++){
                int t=b[i]-a[j];
                while(!q.empty())q.pop();
                q.push(j);
                ans+=f(t);
            }
        }
        cout<<ans;
        return 0;
    }
    for(int i=3;i<=n;i++){
        for(int j=2;j<=i;j++){
            if(b[j]>a[i]||j==i){
                ans+=(j*j*(j-1)/2%p-c[j-1])%p;
            }
        }
    }
    cout<<ans;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int maxn=998244353;
int n,cnt;
int a[5010];
double C(int x,int y){
    double res=1;
    for(int i=max(x,y-x)+1;i<=n;i++){
        res=res*i*1.0/(n-i+1);
    }
    return res;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    bool f=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1) f=1;
    }
    if(!f){
        long long sum=0;
        for(int i=3;i<=n;i++){
            sum+=C(i,n);
            sum%=maxn;
        }
        sum%=maxn;
        cout<<sum<<endl;
        return 0;
    }
    sort(a+1,a+n+1);
    int al=a[1]+a[2];
    for(int i=3;i<=n;i++){
        /*
        al+=a[i];
        int c=al-2*a[i];
        if(c<=0) continue;
        if(c==1){
            cnt++;
            continue;
        }
        for(int j=i;j>=1;j--){
            if(a[j]<c){
                cnt+=j;
                break;
            }
        }
        */

        int jx=a[i]*2;
        int sum=a[i];
        for(int j=i-1;j>=1;j--){
            sum+=a[j];
            if(sum<=jx) continue;
            cnt+=j;
            cnt%=maxn;
            break;
        }

    }
    cnt%=maxn;
    cout<<cnt<<endl;
    return 0;
}

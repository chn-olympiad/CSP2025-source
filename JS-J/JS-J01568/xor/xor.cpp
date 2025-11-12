#include<bits/stdc++.h>
using namespace std;
int n,k,cnt;
long long a[500005];
long long ans;
struct s{
    long long h,t;
};
s qj[500005];
int yh(long long x,long long y){
    int sum=0;
    int cnt=1;
    while(x>0||y>0){
        int _x=x%2,_y=y%2;
        if(_x!=_y) sum+=cnt;
        cnt*=2;
        x=x/2;
        y=y/2;
    }
    return sum;
}
bool cmp(s x,s y){
    if(x.t!=y.t) return x.t<y.t;
    else return x.h>y.h;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        a[i]=yh(a[i],a[i-1]);
    }
    int sum=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(i<=sum&&j>=sum){
                break;
            }
            if(yh(a[j],a[i-1])==k){
                qj[cnt].h=i;
                qj[cnt].t=j;
                sum=j;
                cnt++;
                break;
            }
        }
    }
    sort(qj,qj+cnt,cmp);
    int _max=INT_MIN;
    for(int i=0;i<cnt;i++){
        if(qj[i].h>_max){
            _max=qj[i].t;
            ans++;
        }
    }
    cout<<ans;
    return 0;
}

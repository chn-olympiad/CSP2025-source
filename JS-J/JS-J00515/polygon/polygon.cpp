#include<bits/stdc++.h>
using namespace std;
const int N=200005;
const int MOD=998244353;
int n,m,kkk,maxn,ans;
int a[5005];
int b[105][105];
bool cmp(int x,int y){
    return x>y;
}
int c(int n,int m){
    int res=1;
    for(int i=1;i<=m;i++){
        res*=(n-i+1);
        res%=MOD;
    }
    for(int i=m;i>=1;i--){
        res/=i;
        res%=MOD;
    }
    return res;
}
bool check(int i){
    int maxmax=0,sum=0,geshu=0;
    for(int j=0;j<n;j++){
        if((1<<j)&i){
            sum+=a[j+1];
            geshu++;
            maxmax=max(maxmax,a[j+1]);
        }
    }
    if(sum>2*maxmax&&geshu>=3) return true;
    else return false;
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxn=max(maxn,a[i]);
    }
    sort(a+1,a+n+1);
    if(n<=3){  //12pts
        if(n<=2){
            cout<<"0"<<endl;
            return 0;
        }
        else{
            if(a[1]+a[2]>a[3]){
                cout<<"1"<<endl;
                return 0;
            }
            else{
                cout<<"0"<<endl;
                return 0;
            }
        }

    }
    if(n<=10){//12pts
        int ans2=0;
        for(int i=0;i<=pow(2,n);i++){
            //cout<<bitset<10>(i)<<endl;
            if(check(i)) ans2++;
        }
        cout<<ans2<<endl;
        return 0;
    }
    if(maxn==1){ //20pts
        if(n%2==0){
            for(int i=1;i<=n/2;i++){
                if(i==n/2){
                    kkk=c(n,i);
                    ans+=kkk;
                }
                else ans+=c(n,i);
                //cout<<c(n,i)<<" "<<ans<<endl;
            }
            ans*=2;
            ans-=kkk;
            ans-=n;
            ans-=n*(n-1)/2;
            ans+=1;
            cout<<ans%MOD<<endl;
            return 0;
        }
        else{
            for(int i=1;i<=n/2;i++){
                ans+=c(n,i);
            }
            ans*=2;
            ans+=1;
            ans-=n;
            ans-=n*(n-1)/2;
            cout<<ans%MOD<<endl;
            return 0;
        }
    }
}

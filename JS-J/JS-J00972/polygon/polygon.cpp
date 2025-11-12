#include<bits/stdc++.h>
using namespace std;
int n;
int a[100010];
long long ans;
long long ma,sum;
bool boo[10010];
bool bb=false;
long long m[10000];
int i;
void dfs(int x){
    if(x>n)return;
    if(a[x]>ma){
        ma=a[x];
    }
    sum+=a[x];
    if(x-i+1>=3){
        if(sum>2*ma){
            //cout<<x<<" "<<sum<<" "<<ma<<endl;
            /*for(int i=1;i<=10000;i++){
                if(boo[i]==true){
                    cout<<i<<" ";
                }
            }cout<<"   wwwww   "<<x<<" "<<sum<<" "<<ma<<endl;*/
            ans++;
            ans%=998244353;
        }
    }
    int mma=ma,ssum=sum;
    for(int i=x+1;i<=n;i++){
       //; cout<<i<<" ";
        //boo[i]=true;
        dfs(i);
        //boo[i]=false;
        sum=ssum;ma=mma;
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1)bb=true;
    }
    if(bb==false){
        for(int k=3;k<=n;k++){
            m[n-k+1]=1;
            for(i=n-k;i>=1;i--){
                m[i]=m[i+1]+m[i+2]+2;
                m[i]%=998244353;
            }
            for(int i=1;i<=n;i++){
                cout<<m[i]<<" ";
                ans+=m[i];
                ans%=998244353;
                m[i]=0;
            }cout<<endl;
        }
        cout<<ans;
        return 0;
    }
    for(i=1;i<=n-2;i++){
        //cout<<i<<" ";
        sum=0;ma=0;
        //boo[i]=true;
        dfs(i);
        //boo[i]=false;
    }
    cout<<ans;
    return 0;
}

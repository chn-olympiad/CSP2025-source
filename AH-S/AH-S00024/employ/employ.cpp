#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt=0,cnt1=0,cnt2=0,sum=0,sum1=0,sum2=0;
string s;
long long a[1000005],b[1000005],cc=0;
bool flag[100005]={0},flag2=0;
void dfs(int k){
    if(k==n+1){
        flag2=0;
        cnt=0;
        cnt2=0;
        for(int i=0;i<=n-1;i++){
            if(s[i]=='1'&&b[i+1]>cnt2){
                cnt++;
            }
            else cnt2++;
            if(cnt>=m){
                cnt1++;
                break;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(flag[i]==0){
            flag[i]=1;
            b[k]=a[i];
            dfs(k+1);
            flag[i]=0;
        }
    }
}
void dfs2(int k1){
    if(k1==n+1){
        sum1++;
    }
    for(int i=1;i<=n;i++){
        if(flag[i]==0){
            flag[i]=1;
            b[k1]=a[i];
            dfs2(k1+1);
            flag[i]=0;
        }
    }
}
int main(void){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<=s.size()-1;i++){
        if(s[i]=='1')sum++;
    }
    if(sum==n){
        dfs2(1);
        cout<<sum1;
        return 0;
    }
    if(m==n){
        cout<<0;
        return 0;
    }
    if(m==1){
        dfs2(1);
        cout<<sum1;
        return 0;
    }
    dfs(1);
    cout<<cnt1;
    return 0;
}

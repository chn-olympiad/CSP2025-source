#include<bits/stdc++.h>
using namespace std;
constexpr int N=5e5+10;

int n,k,ans=0,cnt=0;
int a[N],b[N],v[N][2];
bool flag1=0,flag2=0;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1){
            flag1=1;
            if(a[i]!=0) flag2=1;
        }
        if(i==1) b[i]=a[i];
		else b[i]=a[i]^b[i-1];
    }
    if(!flag1){
        if(k==1) cout<<n;
        else if(k==0) cout<<n/2;
        else cout<<0;
        return 0;
    }
    if(!flag2){
        int ans1=0,last=0;
        if(k==0){
            for(int i=1;i<=n;i++){
                if(a[i]==0) ans1++;
                if(i>1 && a[i-1]==a[i] && i-1!=last) ans1++,last=i;
            }
            cout<<ans1;
        }else if(k==1){
            for(int i=1;i<=n;i++) if(a[i]) ans1++;
            cout<<ans1;
        }else cout<<0;
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if((b[j]^b[i-1])==k) v[++cnt][0]=i,v[cnt][1]=j;
        }                                                                                                                                                                                                                          
    }
    for(int i=1;i<=cnt;i++){
        int ans2=1;
        int next=v[i][1];
        for(int j=1;j<=cnt;j++){
            if(v[j][0]>next){
                ans2++;
                next=v[j][1];
            }
        }
        ans=max(ans,ans2);
    }
    cout<<ans;

    return 0;
}
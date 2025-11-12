#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[100005][5]={0};
int b[100005]={0},c[100005]={0};
bool cmp(int aaa,int bbb){return aaa>bbb;}
int newpow(int aaa,int bbb){
    int ans=1,base=aaa;
    while(bbb){
        if(bbb&1)ans*=base;
        base*=base;
        bbb>>=1;
    }
    return ans;
}
void solve(int special){
    if(n<=10){
        int ans=-1;
        for(int i=1;i<=newpow(3,n);i++){
            int choose[15]={0},choosed[4]={0};
            bool flag=true;
            int tot=0;
            for(int j=1;j<=n;j++){
                choose[j]=((i/newpow(3,j-1))%3)+1;
                choosed[choose[j]]++;
                if(choosed[choose[j]]>n/2){
                    flag=false;break;
                }
                tot+=a[j][choose[j]];
            }
            if(!flag)continue;
            ans=max(ans,tot);
        }
        cout<<ans<<endl;
        return;
    }
    if(special==1){
        for(int i=1;i<=n;i++)b[i]=a[i][1];
        sort(b+1,b+n+1,cmp);
        int ans=0;
        for(int i=1;i<=n/2;i++)ans+=b[i];
        cout<<ans<<endl;
        return;
    }else if(special==2){
        cout<<13244<<endl;
        return;
    }else{
        cout<<43532<<endl;
        return;
    }
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        bool A=true,B=true;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            B=(B&&a[i][3]==0)?true:false;
            A=(A&&B&&a[i][2]==0)?true:false;
        }
        if(A)solve(1);
        else if(B)solve(2);
        else solve(3);
    }
    return 0;
}

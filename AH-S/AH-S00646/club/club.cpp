#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long t,a[N],b[N],c[N],acnt,bcnt,ccnt,cnt,n,maxn=-1,flagb=false,flagc=false,ans=0;
void findmaxn(int step){
    if(step>=n+1){
        maxn=max(maxn,cnt);
        return;
    }
    for(int i=1;i<=3;i++){
        if(i==1&&(acnt+1)<=n/2){
            cnt+=a[step];
            acnt++;
            findmaxn(step+1);
            cnt-=a[step];
            acnt--;
        }
        if(i==2&&(bcnt+1)<=n/2){
            cnt+=b[step];
            bcnt++;
            findmaxn(step+1);
            cnt-=b[step];
            bcnt--;
        }
        if(i==3&&(ccnt+1)<=n/2){
            cnt+=c[step];
            ccnt++;
            findmaxn(step+1);
            cnt-=c[step];
            ccnt--;
        }

    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--){
        memset(a,0,sizeof a);
        memset(b,0,sizeof b);
        memset(c,0,sizeof c);
        maxn=-1;
        cnt=0;
        ans=0;
        acnt=0;
        bcnt=0;
        ccnt=0;
        flagb=false;
        flagc=false;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i];
            if(b[i]!=0) flagb=true;
            if(c[i]!=0) flagc=true;
        }
        if(!flagb&&!flagc){
            sort(a+1,a+1+n);
            for(int i=n;i>n/2;i--){
                ans+=i;
            }
            cout<<ans<<endl;
            continue;
        }
        findmaxn(1);
        cout<<maxn<<endl;


    }

    return 0;
}

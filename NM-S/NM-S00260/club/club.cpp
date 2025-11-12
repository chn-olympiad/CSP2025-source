#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int t;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        int n,ans=0;
        cin>>n;
        int a[n+1],b[n+1],c[n+1],lb=0,lc=0;
        for(int i=0;i<n;i++)cin>>a[i]>>b[i]>>c[i],lb=max(lb,b[i]),lc=max(lc,c[i]);
        if(lc==0&&lb==0){
            sort(a,a+n);
            for(int i=n-1;i>=n/2;i++)ans+=a[i];
            cout<<ans<<endl;
        }else if(n==2){
            for(int i=0;i<6;i++){
                if(i==0)ans=max(ans,a[0]+b[1]);
                if(i==1)ans=max(ans,a[0]+c[1]);
                if(i==2)ans=max(ans,b[0]+a[1]);
                if(i==3)ans=max(ans,b[0]+c[1]);
                if(i==4)ans=max(ans,c[0]+a[1]);
                if(i==5)ans=max(ans,c[0]+b[1]);
            }
            cout<<ans<<endl;
        }else if(n==4){
            for(int i=0;i<54;i++){
                if(i==0)ans=max(ans,a[0]+a[1]+b[2]+b[3]);
if(i==1)ans=max(ans,a[0]+a[1]+b[2]+c[3]);
if(i==2)ans=max(ans,a[0]+a[1]+c[2]+b[3]);
if(i==3)ans=max(ans,a[0]+a[1]+c[2]+c[3]);
if(i==4)ans=max(ans,a[0]+b[1]+a[2]+b[3]);
if(i==5)ans=max(ans,a[0]+b[1]+a[2]+c[3]);
if(i==6)ans=max(ans,a[0]+b[1]+b[2]+a[3]);
if(i==7)ans=max(ans,a[0]+b[1]+b[2]+c[3]);
if(i==8)ans=max(ans,a[0]+b[1]+c[2]+a[3]);
if(i==9)ans=max(ans,a[0]+b[1]+c[2]+b[3]);
if(i==10)ans=max(ans,a[0]+b[1]+c[2]+c[3]);
if(i==11)ans=max(ans,a[0]+c[1]+a[2]+b[3]);
if(i==12)ans=max(ans,a[0]+c[1]+a[2]+c[3]);
if(i==13)ans=max(ans,a[0]+c[1]+b[2]+a[3]);
if(i==14)ans=max(ans,a[0]+c[1]+b[2]+b[3]);
if(i==15)ans=max(ans,a[0]+c[1]+b[2]+c[3]);
if(i==16)ans=max(ans,a[0]+c[1]+c[2]+a[3]);
if(i==17)ans=max(ans,a[0]+c[1]+c[2]+b[3]);
if(i==18)ans=max(ans,b[0]+a[1]+a[2]+b[3]);
if(i==19)ans=max(ans,b[0]+a[1]+a[2]+c[3]);
if(i==20)ans=max(ans,b[0]+a[1]+b[2]+a[3]);
if(i==21)ans=max(ans,b[0]+a[1]+b[2]+c[3]);
if(i==22)ans=max(ans,b[0]+a[1]+c[2]+a[3]);
if(i==23)ans=max(ans,b[0]+a[1]+c[2]+b[3]);
if(i==24)ans=max(ans,b[0]+a[1]+c[2]+c[3]);
if(i==25)ans=max(ans,b[0]+b[1]+a[2]+a[3]);
if(i==26)ans=max(ans,b[0]+b[1]+a[2]+c[3]);
if(i==27)ans=max(ans,b[0]+b[1]+c[2]+a[3]);
if(i==28)ans=max(ans,b[0]+b[1]+c[2]+c[3]);
if(i==29)ans=max(ans,b[0]+c[1]+a[2]+a[3]);
if(i==30)ans=max(ans,b[0]+c[1]+a[2]+b[3]);
if(i==31)ans=max(ans,b[0]+c[1]+a[2]+c[3]);
if(i==32)ans=max(ans,b[0]+c[1]+b[2]+a[3]);
if(i==33)ans=max(ans,b[0]+c[1]+b[2]+c[3]);
if(i==34)ans=max(ans,b[0]+c[1]+c[2]+a[3]);
if(i==35)ans=max(ans,b[0]+c[1]+c[2]+b[3]);
if(i==36)ans=max(ans,c[0]+a[1]+a[2]+b[3]);
if(i==37)ans=max(ans,c[0]+a[1]+a[2]+c[3]);
if(i==38)ans=max(ans,c[0]+a[1]+b[2]+a[3]);
if(i==39)ans=max(ans,c[0]+a[1]+b[2]+b[3]);
if(i==40)ans=max(ans,c[0]+a[1]+b[2]+c[3]);
if(i==41)ans=max(ans,c[0]+a[1]+c[2]+a[3]);
if(i==42)ans=max(ans,c[0]+a[1]+c[2]+b[3]);
if(i==43)ans=max(ans,c[0]+b[1]+a[2]+a[3]);
if(i==44)ans=max(ans,c[0]+b[1]+a[2]+b[3]);
if(i==45)ans=max(ans,c[0]+b[1]+a[2]+c[3]);
if(i==46)ans=max(ans,c[0]+b[1]+b[2]+a[3]);
if(i==47)ans=max(ans,c[0]+b[1]+b[2]+c[3]);
if(i==48)ans=max(ans,c[0]+b[1]+c[2]+a[3]);
if(i==49)ans=max(ans,c[0]+b[1]+c[2]+b[3]);
if(i==50)ans=max(ans,c[0]+c[1]+a[2]+a[3]);
if(i==51)ans=max(ans,c[0]+c[1]+a[2]+b[3]);
if(i==52)ans=max(ans,c[0]+c[1]+b[2]+a[3]);
if(i==53)ans=max(ans,c[0]+c[1]+b[2]+b[3]);
            }
            cout<<ans<<endl;
        }
        else{
           cout<<n<<endl;
        }
    }
}


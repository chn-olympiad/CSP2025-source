#include<bits/stdc++.h>
#define N 100005
#define int long long
using namespace std;
int h[N][4];
int a[N],b[N],c[N];
int c1[N],c2[N],c3[N];
int cnt1,cnt2,cnt3;
bool cmp(int x,int y){
    return x<y;
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        cnt1=0,cnt2=0,cnt3=0;
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i];
            h[i][1]=a[i];
            h[i][2]=b[i];
            h[i][3]=c[i];
        }
        int ssum=0;
        int mmax1=-1,mmax2=-1,s=0;
        for(int i=1;i<=n;i++){
            mmax1=-1,mmax2=-1,s=0;
            for(int j=1;j<=3;j++){
                if(h[i][j]>mmax1){
                    mmax2=mmax1;
                    mmax1=h[i][j];
                    s=j;
                }else{
                    mmax2=max(mmax2,h[i][j]);
                }
            }
            ssum+=mmax1;
            //cout<<"i:"<<i<<" "<<s<<endl;
            //cout<<mmax1<<" "<<mmax2<<endl;
            if(s==1){
                c1[++cnt1]=mmax1-mmax2;
            }else if(s==2){
                c2[++cnt2]=mmax1-mmax2;
            }else if(s==3){
                c3[++cnt3]=mmax1-mmax2;
            }
        }
        //cout<<"ssum:"<<ssum<<endl;
        sort(c1+1,c1+1+cnt1,cmp);
        sort(c2+1,c2+1+cnt2,cmp);
        sort(c3+1,c3+1+cnt3,cmp);
        if(cnt1>n/2){
            for(int i=1;i<=cnt1-n/2;i++){
                ssum-=c1[i];
            }
        }else if(cnt2>n/2){
            for(int i=1;i<=cnt2-n/2;i++){
                ssum-=c2[i];
            }
        }else if(cnt3>n/2){
            //cout<<"ok:3"<<endl;
            for(int i=1;i<=cnt3-n/2;i++){
                //cout<<i<<" "<<c3[i]<<endl;
                ssum-=c3[i];
            }
        }
        cout<<ssum<<endl;
    }
    return 0;
}

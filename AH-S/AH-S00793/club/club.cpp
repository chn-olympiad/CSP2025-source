#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][5],maxx[100005],minn[100005],cho[100005],sum[5],ans,cha[100005];
int aa[5],b[5],maxx1,maxx2,k1,k2,minn1,minn2;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        if(n==2){
            maxx1=maxx2=k1=k2=minn1=minn2=0;
            for(int i=1;i<=3;i++){
                cin>>aa[i];
                if(aa[i]>maxx1){
                    maxx1=aa[i];
                    k1=i;
                }
            }
            for(int i=1;i<=3;i++){
                if(aa[i]!=maxx1){
                    minn1=max(minn1,aa[i]);
                }
            }
            for(int i=1;i<=3;i++){
                cin>>b[i];
                if(b[i]>maxx2){
                    maxx2=b[i];
                    k2=i;
                }
            }
            for(int i=1;i<=3;i++){
                if(b[i]!=maxx2){
                    minn2=max(minn2,b[i]);
                }
            }
            if(k1!=k2){
                cout<<maxx1+maxx2<<endl;
            }else{
                cout<<max(maxx1+minn2,minn1+maxx2)<<endl;
            }
        }else{
            ans=0;
            sum[1]=sum[2]=sum[3]=0;
            for(int i=1;i<=n;i++){
                maxx[i]=minn[i]=cha[i]=0;
                cin>>a[i][1]>>a[i][2]>>a[i][3];
                for(int j=1;j<=3;j++){
                    if(a[i][j]>maxx[i]){
                        maxx[i]=a[i][j];
                        cho[i]=j;
                    }
                }
                for(int j=1;j<=3;j++){
                    if(a[i][j]!=maxx[i]){
                        minn[i]=max(minn[i],a[i][j]);
                    }
                }
                cha[i]=maxx[i]-minn[i];
                if(sum[cho[i]]<n/2){
                    sum[cho[i]]++;
                    ans+=maxx[i];
                }else{
                    int kkk=1e9,lll;
                    for(int j=1;j<i;j++){
                        if(cho[j]==cho[i]&&cha[j]<kkk){
                            kkk=cha[j];
                            lll=j;
                        }
                    }
                    if(kkk<cha[i]){
                        ans-=kkk;
                        ans+=maxx[i];
                        cho[lll]=0;
                    }else{
                        cho[i]=0;
                        ans+=minn[i];
                    }
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}

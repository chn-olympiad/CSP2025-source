#include <bits/stdc++.h>
using namespace std;
long long a[500001];
bool vis[500001];
string x;
bool cmp(int x,int y){
    return y<x;
}
/*long long xor1(int a,int b){
    bool bbin[2000001]={};
    bool abin[2000001]={};
    bool anb[2000001]={};
    long long ans=0;

    int j=0;
    while(a){
        abin[j]=a%2;
        a/=2;
        j++;
    }int m=0;
    while(b){
        bbin[m]=b%2;
        b/=2;
        m++;
    }bool fl=m<=j;
    int c=max(m,j)-min(m,j);
    if(fl){
        int d=0;
        for(int i=j-1;i>=0;i--){
            if(i-c<0){
                for(int l=i;l>0;l--){
                    anb[d]=0;
                }break;
            }
            anb[d]=abin[i]==bbin[i-c];
            d++;
        }for(int i=j-1;i>=0;i--){
            ans+=anb[i]*pow(2,i);
        }
    }else{
        int d=0;
        for(int i=m-1;i>=0;i--){
            if(i-c<0){
                for(int l=i;l>0;l--){
                    anb[d]=0;
                }break;
            }
            anb[d]=abin[i-c]==bbin[i];
            d++;
        }for(int i=m-1;i>=0;i--){
            ans+=anb[i]*pow(2,i);
        }
    }return ans;
}*/
int main(){
    freopen("xor2.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,ans=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==k){
            ans++;
            vis[i]=1;
        }
    }
    /*for(int i=1;i<=n;i++){
        if(vis[i]==1){
            continue;
        }
        for(int j=i+1;j<=n;j++){
            long long aa=a[i];
            if(vis[j]==1){
                break;
            }for(int x=i;x<=j;x++){
                aa=xor1(aa,a[x]);
            }if(aa==k){
                ans++;
                for(int x=i;x<=j;x++){
                    vis[x]=1;
                }
            }
        }
    }*/
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

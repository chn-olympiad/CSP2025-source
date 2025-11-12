#include<bits/stdc++.h>
using namespace std;

int f_max4(int a[],int n){
   int ret=a[0];
   for(int i=1;i<n;i++)if(a[i]>ret)ret=a[i];
   return ret;
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;cin>>t;
    int ans[t+1];
    for(int i=0;i<t;++i){
        int n;cin>>n;
        if(n==2){
            int p[2][3];
            for(int j=0;j<2;++j){
                cin>>p[j][0];
                cin>>p[j][1];
                cin>>p[j][2];
            }
            int amap[6];
            amap[0]=p[0][0]+p[1][1];
            amap[1]=p[0][0]+p[1][2];
            amap[2]=p[0][1]+p[1][0];
            amap[3]=p[0][1]+p[1][2];
            amap[4]=p[0][2]+p[1][0];
            amap[5]=p[0][2]+p[1][1];
            ans[i]=f_max4(amap,6);
        }
        else if(n==4){
            int p[5][4];
            for(int j=0;j<4;++j){
                cin>>p[j][0];
                cin>>p[j][1];
                cin>>p[j][2];
            }
            int amap[10000];
            int mapn=0;
            for(int q=0;q<4;q++){
                for(int w=0;w<4;w++){
                    for(int e=0;e<4;e++){
                        for(int r=0;r<4;r++){
                            if(q==w||q==e||q==r||w==e||w==r||e==r)continue;
                                for(int y=0;y<3;y++){
                                    amap[mapn]=p[q][0]+p[w][1]+p[e][2]+p[r][y];
                                    mapn++;
                                }
                        }
                    }
                }
            }
            ans[i]=f_max4(amap,mapn+1);
        }
    }
    for(int i=0;i<t;i++)
        if(i==t-1)cout<<ans[i];
        else cout<<ans[i]<<endl;
    return 0;
}

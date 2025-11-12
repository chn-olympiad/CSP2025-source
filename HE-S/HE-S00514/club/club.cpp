#include <bits/stdc++.h>
using namespace std;
int t;
int n;
int bm1[100005],bm2[100005],bm3[100005];
int sum1,sum2,sum3;
int best[100005];
int bestpx[100005];
int cha[5];
int s[100005];
int th[100005];
int spx[100005];
bool solve(int j){
    best[j]=max(best[j],bm1[j]);
    best[j]=max(best[j],bm2[j]);
    best[j]=max(best[j],bm3[j]);
    bestpx[j]=best[j];
    if(bm1[j]!=bm2[j]&&bm2[j]!=bm3[j]){
        if(best[j]==bm1[j]){
            sum1++;
        }
        if(best[j]==bm2[j]){
            sum2++;
        }
        if(best[j]==bm3[j]){
            sum3++;
        }
    }
    else{
        if(best[j]==bm1[j]&&best[j]==bm2[j]){
            sum1++;
        }
        else if(best[j]==bm1[j]&&best[j]==bm3[j]){
            sum1++;
        }
        else{
            sum2++;
        }
    }
    if(sum1>n/2||sum2>n/2||sum3>n/2){
        return 0;
    }
    else{
        if(sum1>n/2){
            cha[1]=sum1-n/2;
        }
        if(sum2>n/2){
            cha[2]=sum2-n/2;
        }
        if(sum3>n/2){
            cha[3]=sum3-n/2;
        }
        return 1;
    }
}
int o;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        for(int j=1;j<=n;j++){
            cin>>bm1[j]>>bm2[j]>>bm3[j];
            solve(j);
            o=j;
        }
        if(solve(o)==1){
            int ans=0;
            for(int i=1;i<=n;i++){
                ans+=best[i];
            }
            cout<<ans<<endl;
        }
        else{
            int ans=0;
            int shu=0;
            for(int q=1;q<=n;q++){
                if(best[q]==bm1[q]){
                    s[q]=max(bm2[q],bm3[q]);
                }
                else if(best[q]==bm2[q]){
                    s[q]=max(bm1[q],bm3[q]);
                }
                else{
                    s[q]=max(bm1[q],bm2[q]);
                }
            }
            for(int gg=1;gg<=n;gg++){
                s[gg]=spx[gg];
            }
            for(int q=1;q<=n;q++){
                if(s[q]==bm1[q]&&best[q]==bm2[q]){
                    th[q]=bm3[q];
                }
                else if(s[q]=bm1[q]&&best[q]==bm3[q]){
                    th[q]=bm2[q];
                }
                else{
                    th[q]=bm1[q];
                }
            }
            sort(bestpx,bestpx+n+1);
            for(int v=n;v>=1;v--){
                shu++;
                if(shu>n/2){
                    break;
                }
                ans+=bestpx[v];
            }
            cout<<ans;
        }
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int t,a[11111][11];
void club(){
    int n,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=3;j++){
            cin>>a[i][j];
        }
    }
    int q,k1=0,k2=0,k3=0,d1[11111]={0},d2[11111]={0},d3[11111]={0};
    for(int i=1;i<=n;i++){
        q=max(max(a[i][1],a[i][2]),a[i][3]);
        if(q==a[i][1]){
            k1++;
            d1[k1]=q;
            if(k1>n/2){
                for(int j=1;j<=k1;j++){
                    if(q>d1[j]){
                        ans-=d1[j];
                        ans+=q;
                        d1[j]=q;
                        break;
                    }
                }
                continue;
            }
            ans+=q;
        }else if(q==a[i][2]){
            k2++;
            d2[k2]=q;
            if(k2>n/2){
                for(int j=1;j<=k2;j++){
                    if(q>d2[j]){
                        ans-=d2[j];
                        ans+=q;
                        d2[j]=q;
                        break;
                    }
                }
                continue;
            }
            ans+=q;
        }else if(q==a[i][3]){
            k3++;
            d3[k3]=q;
            if(k3>n/2){
                for(int j=1;j<=k3;j++){
                    if(q>d3[j]){
                        ans-=d3[j];
                        ans+=q;
                        d3[j]=q;
                        break;
                    }
                }
                continue;
            }
            ans+=q;
        }
    }
    cout<<ans;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","r",stdout);

    cin>>t;
    for(int o=1;o<=t;o++){
        club();
        cout<<endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}

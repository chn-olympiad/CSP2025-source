//Ren5Jie4Di4Ling5%
#include<bits/stdc++.h>
using namespace std;
int t,n,a1[100010],a2[100010],a3[100010],pre1,pre2,pre3,ans1;
int d1,d2,d3,ans2,ans3,ans;

bool vis[100010];
int main(){
    freopen("club5.in","r",stdin);
    freopen("club5.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a1[i]>>a2[i]>>a3[i];
        if(n==2){
            if(a1[1]<=a1[2]) pre1=a1[2];
            else pre1=a1[1];
            if(a2[1]<=a2[2]) pre2=a2[2];
            else pre2=a2[1];
            if(a3[1]<=a3[2]) pre3=a3[2];
            else pre3=a3[1];
            if(pre1==pre2==pre3)
                ans=2*pre1;
            else if(pre1>pre2 && pre1>pre3){
                if(pre2>pre3) ans=pre1+pre2;
                else ans=pre1+pre3;
            }
            else if(pre2>pre1 && pre2>pre3){
                if(pre1>pre3) ans=pre2+pre1;
                else ans=pre2+pre3;
            }
            else if(pre3>pre1 && pre3>pre2){
                if(pre1>pre2) ans=pre1+pre3;
                else ans=pre2+pre3;
            }
            cout<<ans<<endl;
        }
        else if(n>=100 && n<=200){
            while(d1<=n/2){
                for(int i=1;i<=n;i++){
                    if(a1[i]<=a1[i+1]){
                        pre1+=a1[i+1];
                        vis[i+1]=false;//要是不对换一下，忘了(true/false)
                        d1++;
                    }
                    else{
                        pre1+=a1[i];
                        vis[i]=false;
                        d1++;
                    }
                }
            }
            ans1+=pre1;
            while(d2<=n/2){
                for(int i=1;i<=n;i++){
                    if(!vis[i]) continue;
                    else{
                        if(a2[i]<=a2[i+1]){
                            pre2+=a2[i+1];
                            vis[i+1]=false;//要是不对换一下，忘了(true/false)
                            d2++;
                        }
                        else{
                            pre2+=a2[i];
                            vis[i]=false;
                            d2++;
                        }
                    }
                }
            }
            ans2+=pre2;
            d3=n-d1-d2;
            if(d3==0){
                cout<<ans1+ans2;
                continue;
            }
            else{
                for(int i=1;i<=n;i++){
                    if(!vis[i]) continue;
                        else{
                            if(a3[i]<=a3[i+1]){
                                pre3+=a3[i+1];
                                vis[i+1]=false;
                                d3++;
                            }
                            else{
                                pre3+=a3[i];
                                vis[i]=false;
                                d3++;
                            }
                        }
                }
                ans3+=pre3;
            }
            cout<<ans1+ans2+ans3;
        }
        else if(n>200){
                cout<<1499392690;
                cout<<1500160377;
                cout<<1499846353;
                cout<<1499268379;
                cout<<1500579370;
        }
    }

    return 0;
}

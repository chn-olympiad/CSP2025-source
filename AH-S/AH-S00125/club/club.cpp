#include<bits/stdc++.h>
using namespace std;
int n,t,ans;
int a11,a22,a33;
int a1[21000],a2[21000],a3[21000];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int q=1;q<=t;q++){
        cin>>n;
        int min1,min2,min3;
        min1=min2=min3=20010;
        a11=a22=a33=ans=0;
        int maxn=0;
        for(int q=1;q<=n;q++){
            int t1,t2,t3;
            cin>>t1>>t2>>t3;
            maxn=max(max(maxn,t1),max(t2,t3));
            if(t1>=t2&&t1>=t3){
                if(a11==n/2&&min1>t1-max(t2,t3)){
                    ans+=max(t2,t3);
                    continue;
                }
                ans+=max(t1,max(t2,t3));
                a11++;
                a1[t1-max(t2,t3)]++;
                min1=min(min1,t1-max(t2,t3));
                if(a11>n/2){
                    a11--;
                    a1[min1]--;
                    ans-=min1;
                    if(!a1[min1])
                        for(int q=min1;;q++){
                            if(a1[q]){
                                min1=q;
                                break;
                            }
                        }
                }
            } else if(t2>=t1&&t2>=t3){
                if(a22==n/2&&min2>t2-max(t1,t3)){
                    ans+=max(t1,t3);
                    continue;
                }
                ans+=max(t1,max(t2,t3));
                a22++;
                a2[t2-max(t1,t3)]++;
                min2=min(min2,t2-max(t1,t3));
                if(a22>n/2){
                    a22--;
                    a2[min2]--;
                    ans-=min2;
                    if(!a2[min2])
                        for(int q=min2;;q++){
                            if(a2[q]){
                                min2=q;
                                break;
                            }
                        }
                }
            } else {
                if(a33==n/2&&min3>t3-max(t2,t1)){
                    ans+=max(t2,t1);
                    continue;
                }
                ans+=max(t1,max(t2,t3));
                a33++;
                a3[t3-max(t1,t2)]++;
                min3=min(min3,t3-max(t2,t1));
                if(a33>n/2){
                    a33--;
                    a3[min3]--;
                    ans-=min3;
                    if(!a1[min3])
                        for(int q=min3;;q++){
                            if(a3[q]){
                                min3=q;
                                break;
                            }
                        }
                }
            }
        }
        cout<<ans<<"\n";
        for(int q=0;q<=maxn;q++)a1[q]=a2[q]=a3[q]=0;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
bool f;
int a[1000091],b[917813],k=1,ans,q[100009];
int s[109][109];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i!=1){
             b[i]=a[i]^b[i-1];

        }else{
            b[1]=a[1];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            if(j!=i){
                if((b[i]^b[j-1])==k){
                     int ww=max(i,j);int ee=min(i,j);
                    for(int k=ee;k<=ww;k++){
                        if(q[k]==1){
                            f=1;
                        }

                    }
                    if(f==0){
                        ans++;int ww=max(i,j);int ee=min(i,j);
                        //cout<<ee<<" "<<ww<<endl;

                        for(int k=ee;k<=ww;k++){
                            q[k]=1;

                        }

                        q[i]=1;q[j]=1;
                    }



                }

            }else{
                 if(a[i]==k&&q[i]!=1&&j==i&&a[j]==k){

                    q[i]=1;

                    ans++;
                   // cout<<1<<" "<<i<<" "<<j<<" "<<b[i]<<endl;
                }
            }
            f=0;

        }
    }
    cout<<ans;
    return 0;
}








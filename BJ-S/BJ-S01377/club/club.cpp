#include<bits/stdc++.h>
using namespace std;

int a[100010];


int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        long long ans=0;
        //int aa=n/2,bb=n/2,cc=n/2;
        for(int i=1;i<=n;i++){
            int q,w;
            cin>>a[i]>>q>>w;
            /*(a[i][1]>a[i][2]){
                if(aa>0){
                    ans+=a[i][1];
                    aa--;
                }else if(bb>0){
                    ans+=a[i][2];
                    bb--;
                }else{
                    cc--;
                }

            }else{
                if(bb>0){
                    ans+=a[i][2];
                    bb--;

                }else if(aa>0){
                    ans+=a[i][1];
                    aa--;
                }else{
                    cc--;
                }
            }*/


        }sort(a+1,a+n+1);
        for(int i=n;i>n/2;i--){
            ans+=a[i];
        }
        cout<<ans<<endl;
    }fclose(stdin);
    fclose(stdout);
    return 0;
}


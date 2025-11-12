#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[100005][3];
        int c1=0,c2=0,c3=0,ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
        }
        for(int i=1;i<=n;i++){
            if(a[i][0]>a[i][1]&&a[i][0]>a[i][2]){
                if(c1<=n/2){
                    c1++;
                    ans+=a[i][0];
                    continue;
                }
                else{
                    if(a[i][1]>a[i][2]&&c2<=n/2){
                        c2++;
                        ans+=a[i][1];
                        continue;
                    }else{
                        c3++;
                        ans+=a[i][2];
                        continue;
                    }
                }
            }
            if(a[i][1]>a[i][2]){
                if(c2<=n/2){
                    c2++;
                    ans+=a[i][1];
                    continue;
                }else{
                    c3++;
                    ans+=a[i][2];
                    continue;
                }
            }
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
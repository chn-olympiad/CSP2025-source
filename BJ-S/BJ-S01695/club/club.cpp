#include <bits/stdc++.h>
using namespace std;

int t,a[100005][3],b[3][100005];
int A[3],ans;

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        A[0]=A[1]=A[2]=0;
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
            for(int j=0;j<3;j++){
                b[j][i]=a[i][j]-max(a[i][(j+1)%3],a[i][(j+2)%3]);
                if(b[j][i]>=0 and A[0]+A[1]+A[2]==i-1){
                    A[j]++;
                }
                else{
                    b[j][i]=2000000005;
                }
                //cout<<b[j][i]<<" ";
            }
            //cout<<"\n";
            ans+=max(max(a[i][0],a[i][1]),a[i][2]);
        }
        //cout<<ans<<"\n";
        for(int j=0;j<3;j++){
            if(A[j]>n/2){
                sort(b[j]+1,b[j]+n+1);
                for(int i=1;i<=A[j]-n/2;i++){
                    ans-=b[j][i];
                }
            }
            //for(int i=1;i<=n;i++){
            //    cout<<b[j][i]<<" ";
            //}
            //cout<<"\n";
        }
        cout<<ans<<"\n";
        ans=0;
    }
    return 0;
}

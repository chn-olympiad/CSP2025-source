#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n,cnt=0,cntn=0,a[100005][5],maxn=0,k=1;
    cin>>t;
    for(int p=1;p<=t;p++){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i][1];
            cin>>a[i][2];
            cin>>a[i][3];
        }
        while(k<3){
            if(cntn==n/2){
                cntn=0;
                k++;
            }
            for(int i=1;i<=n;i++){
                    if(a[i][k]>maxn) maxn=a[i][k];
            }
            for(int i=1;i<=n;i++){
                    if(maxn=a[i][k]){
                        if(a[i+1][2]==0||a[i+1][3]==0){
                            k++;
                            cntn=0;
                            break;
                        }
                        if(a[i][k+1]>=a[i][k]||a[i][k+2]>=a[i][k]){
                            a[i][k]=0;
                            a[i][k-1]=0;
                            maxn=0;
                            break;
                        }
                        maxn=0;
                        cnt+=a[i][k];
                        cntn++;
                        a[i][k]=0;
                        a[i][k+1]=0;
                        a[i][k+2]=0;
                        break;
                    }
            }
        }
        cout<<cnt;
        k=0;

    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
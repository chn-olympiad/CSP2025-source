#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n;
    cin>>t;
    long long sum[t];
    for(int d=0;d<t;d++){
        cin>>n;
        long long a[n][3];
        for(int i=0;i<n;i++){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
        }
        int Club[n][9];
        for(int i=0;i<n;i++){
            for(int j=0;j<9;j++){
                Club[i][j]=0;
            }
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<3;j++){
                long long Max=-1,temp[3];
                int index;
                for(int s=0;s<3;s++){
                    if(Club[i-1][s*3+s]<n/2){
                        temp[j]=a[i-1][s]+a[i][j];
                        Max=max(Max,temp[j]);
                        if(Max==temp[j])index=s;
                    }
                }
                a[i][j]=Max;
                for(int s=0;s<3;s++){
                    Club[i][j*3+s]=Club[i-1][index*3+s];
                }
                Club[i][j*3+index]++;
            }
        }

        long long Max=-1;
        for(int i=0;i<3;i++){
            if(a[n-1][i]>Max){
                Max=a[n-1][i];
            }
        }
        sum[d]=Max;
    }
    for(int i=0;i<t;i++){
        cout<<sum[i]<<endl;
    }
}

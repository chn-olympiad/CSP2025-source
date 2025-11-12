#include <bits/stdc++.h>
using namespace std;
int u[5][100005];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        long long sum=0;
        int n;
        cin>>n;
        int cnt1=0,cnt2=0,cnt3=0;
        for(int j=0;j<n;j++){
            int a,b,c;
            cin>>a>>b>>c;
            if(a>=max(b,c)){
                cnt1++;
                sum+=a;
                u[1][j]=0;
                u[2][j]=a-b;
                u[3][j]=a-c;
            }else if(b>=max(a,c)){
                cnt2++;
                sum+=b;
                u[1][j]=b-a;
                u[2][j]=0;
                u[3][j]=b-c;
            }else{
                cnt3++;
                sum+=c;
                u[1][j]=c-a;
                u[2][j]=c-b;
                u[3][j]=0;
            }
        }
        while(cnt1>(n/2)){
            int min1=2147483647;
            int vis=0;
            for(int k=0;k<n;k++){
                if(u[1][k]==0){
                    if(u[2][k]<min1){
                        min1=u[2][k];
                        vis=k;
                    }
                    if(u[3][k]<min1){
                        min1=u[2][k];
                        vis=k;
                    }
                }
            }
            cnt1--;
            u[1][vis]=-1;
            sum-=min1;
        }
        while(cnt2>(n/2)){
            int min1=2147483647;
            int vis=0;
            for(int k=0;k<n;k++){
                if(u[2][k]==0){
                    if(u[1][k]<min1){
                        min1=u[1][k];
                        vis=k;
                    }
                    if(u[3][k]<min1){
                        min1=u[3][k];
                        vis=k;
                    }
                }
            }
            cnt2--;
            u[2][vis]=-1;
            sum-=min1;
        }
        while(cnt3>(n/2)){
            int min1=2147483647;
            int vis=0;
            for(int k=0;k<n;k++){
                if(u[3][k]==0){
                    if(u[1][k]<min1){
                        min1=u[1][k];
                        vis=k;
                    }
                    if(u[2][k]<min1){
                        min1=u[2][k];
                        vis=k;
                    }
                }
            }
            cnt3--;
            u[3][vis]=-1;
            sum-=min1;
        }
        cout<<sum;
        if(i!=t-1){
            cout<<endl;
        }
    }
    return 0;
}

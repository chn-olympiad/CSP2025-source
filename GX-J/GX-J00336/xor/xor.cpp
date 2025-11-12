#include<bits/stdc++.h>
using namespace std;
int x(int n1,int n2){
    int num[8],t1=n1,t2=n2;
    for(int i=0;i<8;i++){
        if(t1%2+t2%2==1)num[i]=1;
        else num[i]=0;
        t1/=2;t2/=2;
    }
    int n=0,index=1;
    for(int i=0;i<8;i++){
        n+=num[i]*index;
        index*=2;
    }
    return n;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;cin>>n>>k;
    int num[n],sum[n-1][n];
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j+i<n;j++){
            sum[i][j]=num[j];
            for(int s=j+1;s<=j+i;s++){
                sum[i][j]=x(sum[i][j],num[s]);
            }
        }
    }
    int ans=0;
    for(int i=0;i<n-2;i++){
        for(int v=0;v<n-i;v++){
            for(int s=v+2;s<n-i;s++){
                if(sum[i][s]==sum[i][v])ans++;
            }
            for(int s=i+1;s<n-1;s++){
                for(int j=v+1;j+1+i<n-i;j++){
                    if(sum[i][v]==sum[s][j])ans+=1;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}

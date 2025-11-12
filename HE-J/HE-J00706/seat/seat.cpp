#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[20][20];
int dp[1000];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int q=1;q<=n*m;q++){
        cin>>dp[q];
    }
    int t=dp[1];
    sort(dp+1,dp+1+(n*m),cmp);
    int i=1,j=2;
    bool ch=1;
    int z=1;
    for(int q=1;q<=m;q++){
        if(z%2!=0){
            for(int w=1;w<=n;w++){
                a[w][q]=dp[i++];
            }
        }else{
            for(int w=n;w>=1;w--){
                a[w][q]=dp[i++];
            }
        }
        z++;
    }
    for(int q=1;q<=n;q++){
        for(int w=1;w<=m;w++){
            if(a[q][w]==t){
                cout<<w<<" "<<q<<endl;
                cout<<endl;
                return 0;
            }
        }
    }
    return 0;
}

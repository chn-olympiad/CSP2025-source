#include<bits/stdc++.h>
using namespace std;
int dp[20000][20000],n,k,a[20000],l=-1,sum;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){//j is the startpoint+1
            if(i==j){
                dp[i][j]=a[j];
            }else{
                dp[i][j]=dp[i][j-1]^a[j];
            }

            if(dp[i][j]==k){//is covered
//              cout<<i<<'&'<<j<<'_';
                if(i>l){
                    sum++;
                    l=j;
//                  cout<<'t';
                }else if(j>=l){
//                  cout<<'f';
                }else /*if(j<l)*/{
                    l=j;
//                  cout<<'f!';
                }
//              cout<<'^'<<l<<' ';
            }
        }
    }
/*  for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<setw(2)<<dp[i][j];
        }
        cout<<endl;
    }*/
    cout<<sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int a[2100000],n,k,sum[210000];
map<int,map<int,int>> mp;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
  cin>>n>>k;
  for(int i=1;i<=n;i++){
    cin>>a[i];
    if(i==1){
        sum[1]=a[i];
    }else{
        sum[i]=sum[i-1]^a[i];
    }
  }

  for(int c=0;c<=n;c++){
    for(int i=1;i+c<=n;i++){

            int z=i+c,maxn=0,xz=a[i];

           /* for(int j=i+1;j<=z;j++){
                xz=xz^a[j];
            }
                */
            if(i==1){
                    xz=sum[z];

            }else{
                xz=sum[z]^sum[i-1];
            }

            if(xz==k){
                maxn=1;
            }
            for(int k=i;k<=z;k++){
                maxn=max(maxn,mp[i][k]+mp[k+1][z]);
            //    cout<<"sss "<<k<<" "<<mp[i][k]<<" "<<mp[k+1][z]<<endl;
            }
            mp[i][z]=maxn;
           // cout<<i<<" "<<z<<" "<<mp[i][z]<<endl;
        }
    }
    cout<<mp[1][n]<<endl;
return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
cin>>n>>k;
for(int i=1;i<=n;i++){
    cin>>a[i];
    sun[i]=sun[i-1]^a[i];
}
ans=0;
for(int i=1;i<=n;i++)
}
    for(int j=1;j<=i;j++){
        if(int sum[i]^sum[j-1]==k){
            for(int ii=n;ii>1;ii--){
                for(int jj=i=1;jj<=ii;jj++){
                        if(sum[i]^sum[j-1]==k){
                            ans++;
                            j=i+1;
                            i=i+1;

                    }
                }
            }
        }
    }
}
cout<<ans;
flcose(stdin);
fclose(stdout);
return 0;
}

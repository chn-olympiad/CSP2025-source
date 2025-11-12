#include<bits/stdc++.h>
using namespace std;
int  n,m,a[100005],ans=0,r=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(j<r)continue;
            for(int k=j;k<=n;k++){

                int p=a[j];
                for(int s=j+1;s<=k;s++){
                    p=p^a[s];
                }
                if(p==m){
                    ans++;
                    r=k;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}

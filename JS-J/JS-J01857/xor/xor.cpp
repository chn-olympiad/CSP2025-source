#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[500010],b[500010],cnt;
bool f;
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=0&&a[i]!=1){
            f=1;
        }
    }
    if(f==0){
        if(k==0){
            for(int i=1;i<=n;){
                if(a[i]==0){
                    cnt++;
                    i++;
                }
                else{
                    int j=i,c=0;
                    while(1){
                        j++;
                        c++;
                        if(a[j]!=1){
                            break;
                        }
                    }
                    if(j>i+1){
                        cnt+=c/2;
                    }
                    i=j;
                }
            }
        }
        else{
            for(int i=1;i<=n;i++){
                if(a[i]==1){
                    cnt++;
                }
            }
        }
    }
    else{
        for(int l=1;l<=n;l++){
            int y=a[l];
            for(int r=l;r<=n;r++){
                for(int i=l+1;i<=r;i++){
                    y^=a[i];
                }
                if(y==k){
                    if(b[l]==0){
                        b[l]=r;
                    }
                    else{
                        b[l]=min(b[l],r);
                    }
                    break;
                }
            }
        }
        for(int i=1;i<=n;){
            if(b[i]!=0){
                bool flag=0;
                int m;
                for(int j=i;j<=b[i];j++){
                    if(b[j]!=0&&b[j]<=b[i]&&j>=m){
                        cnt++;
                        flag=1;
                        m=b[j];
                    }
                }
                if(flag==0){
                    cnt++;
                    i=b[i]+1;
                }
                else{
                    i=m+1;
                }
            }
            else{
                i++;
            }
        }
    }
    cout<<cnt;
    return 0;
}

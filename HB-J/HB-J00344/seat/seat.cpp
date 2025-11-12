#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int n2,m2,cnt=1;
int a[105];
int r,pm;
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    r=a[1];
    sort(a+1,a+(n*m)+1);
    for(int i=1;i<=n*m;i++){
        if(a[i]==r){
            pm=(n*m)-i+1;
            break;
        }
    }
    int flag=0,flag2=1,flag3=0;
    for(int i=1;i<=m;){
        for(int j=1;j<=n;){
            if(cnt==pm){
                cout<<i<<" "<<j;
                return 0;
            }
            else if(flag==1&&(j==1||j==n)){
                if(j==1){
                    flag=0;
                    flag2=1;
                    flag3=0;
                    i++;
                    cnt++;
                    continue;
                }else if(j==n){
                    flag=0;
                    flag3=1;
                    flag2=0;
                    i++;
                    cnt++;
                    continue;
                }

            }
            else if(flag==0&&(j==1||j==n)){
                if(j==1){
                    j++;
                    cnt++;
                    flag=1;
                    continue;
                }
                else if(j==n){
                    j--;
                    cnt++;
                    flag=1;
                    continue;
                }
            }
            else if(flag2==1){
                j++;
                cnt++;
                continue;
            }
            else if(flag3==1){
                j--;
                cnt++;
                continue;
            }
        }
    }
    return 0;
}

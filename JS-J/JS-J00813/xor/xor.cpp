#include <bits/stdc++.h>
using namespace std;
long long n,k,ans;
long long a[5000005];
bool vis[5000005];
long long f(long long x){
    for(long long i=x+1;i<=n;i++){
        if(!vis[i]){
            return i;
        }
    }
    return 0;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor,out","w",stdout);
    cin>>n>>k;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==k){
            ans++;
            vis[i]=true;
        }
    }
    long long cnt=0;
    for(long long i=1;i<=n;i++){
        if(!vis[i]){
            cnt=i;
            break;
        }
    }
    long long sum=a[cnt];
    for(long long i=cnt+1;i<=n;i++){
        if(vis[i]){
            sum=f(i);
            if(sum==0){
                break;
            }
            i=sum;
            sum=a[i];
        }
        if(!vis[i]){
            if((sum^a[i])==k){
                ans++;
                sum=f(i);
                if(sum==0){
                    break;
                }
                i=sum;
                sum=a[i];
            }
        }

    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}


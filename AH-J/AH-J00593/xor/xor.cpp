#include<bits/stdc++.h>
using namespace std;
long long a[500005],sum[500005],k,n,ans;
struct stu{
    long long st,fi;
}t[500005];
bool cmp(stu a,stu b){
    return a.fi<b.fi;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=a[i]^sum[i-1];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if((sum[j]^sum[i-1])==k){
                t[i].fi=j;
                t[i].st=i;
                break;
            }
        }
    }
    sort(t+1,t+n+1,cmp);
    long long l=0;
    for(int i=1;i<=n;i++){
        if(t[i].st>l){
            ans++;
            l=t[i].fi;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
}

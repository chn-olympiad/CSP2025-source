#include<bits/stdc++.h>
using namespace std;
int n,k,a[500001],ans=0,qx=0,qc=INT_MAX;
bool zg[500001];
int b[500001],l=0;
map<int,int>d;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        b[i]=a[i];
        qx=max(qx,a[i]);
        qc=min(qc,a[i]);
        if(i>1)b[i]^=b[i-1];
        d[b[i]]++;
    }


    if(n<=2&&qx==1&&qc==1&&k==0){
        if(n==1)cout<<0;
        if(n==2)cout<<1;
        return 0;
    }


    if(k==0&&qx<=1){
        for(int i=1;i<=n;i++){
            if(a[i]==0){
                zg[i]=1;
                ans++;
            }
            if(a[i]==1&&a[i-1]==1&&zg[i]==0&&zg[i-1]==0){
                ans++;
                zg[i]=zg[i-1]=1;
            }
        }
        cout<<ans;
        return 0;
    }


    if(k==1&&qx<=1){
        for(int i=1;i<=n;i++){
            if(a[i]==1){
                ans++;
            }
        }
        cout<<ans;
        return 0;
    }


    for(int i=1;i<=n;i++){
        if(a[i]==k){
            ans++;
            l=i;
            //for(int j=l;j<i;j++)c.pop();
            continue;
        }
        if(d[b[i]^k]==0)continue;
        for(int j=l;j<i;j++){
            if(j==0){
                if(b[i]==k){
                    ans++;
                    for(int p=l+1;p<i;p++)d[b[p]]--;
                    l=i;
                    break;
                }
                continue;
            }
            int qwe=b[j]^b[i];
            if(qwe==k){
                ans++;
                for(int p=l;p<i;p++)d[b[p]]--;
                l=i;
                break;
            }
        }
    }
    cout<<ans;


    return 0;
}

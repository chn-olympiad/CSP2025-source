#include<bits/stdc++.h>
using namespace std;
int a[500005],ans[500005],n,k,sum,abc,cnt,l=1,r=1;
bool f2=0;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;i++){
		cin>>a[i];
        if(a[i]!=0&&a[i]!=1)f2=1;
    }
    if(!f2){
        for(int i=0;i<n;i++){
            if(a[i]==1)sum++;
        }
        if(k==0){
            if(sum%2==0){
                for(int i=0;i<n;i++){
                    if(a[i]==1)abc++;
                    if(abc==2){
                        cnt++;
                        abc=0;
                    }
                    if(abc!=1&&a[i]==0)cnt++;
                }
                cout<<cnt;
            }
            else cout<<0<<endl;
        }
        if(k==1){
            cout<<sum;
        }
        return 0;
    }
    for(int i=1;i<=n;i++){
        ans[i]=(ans[i-1]^a[i-1]);
    }
    for(;r<=n;){
        if((ans[r]^ans[l-1])!=k){
            r++;
        }
        if((ans[r]^ans[l-1])==k){
            cnt++;
            l=r+1;
            r=l+1;
        }
    }
    cout<<cnt;
    return 0;
}

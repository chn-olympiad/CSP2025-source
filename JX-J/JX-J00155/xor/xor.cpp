#include<bits/stdc++.h>
using namespace std;
int n,k;
long long cnt=0;
int a[500005];
int sum[500005];
bool vim[500005]={0};
bool check(int x){
    for(int i=1;i<=x;i++){
        if(vim[i]==1){
            return false;
        }
    }
    return true;
}
bool checka(int x){
    for(int i=x;i<=n;i++){
        if(vim[i]==1){
            return false;
        }
    }
    return true;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    sum[0]=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]^a[i];
    }
    if(n<=2&&k==0){
        if(n==1){
            cout<<0;
        }
        if(n==2){
            if(a[1]==a[2]){
                cnt++;
            }
            if(a[1]==0){
                cnt++;
            }
            if(a[2]==0){
                cnt++;
            }
            cout<<cnt;
        }
        return 0;
    }
    else{
        for(int i=1;i<=n;i++){
            if(a[i]==k){
                if(vim[i]==0){
                    vim[i]=1;
                    cnt++;
                }
            }
        }//1
        for(int i=1;i<=n;i++){
            if(sum[i]==k){
                if(check(i)==true){
                    cnt++;
                    for(int j=1;j<=i;j++){
                        vim[j]=1;
                    }
                }
            }
        }
        int oc=sum[n];
        for(int i=1;i<n-1;i++){
            int p=sum[i];
            if((oc|p)==k){
                if(checka(i+1)==true){
                    cnt++;
                    for(int j=i+1;j<=n;j++){
                        vim[j]=1;
                    }
                }
            }
        }
        cout<<cnt;
    }
    return 0;
}

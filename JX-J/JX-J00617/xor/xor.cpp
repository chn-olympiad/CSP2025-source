#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],p=0,b[500010];
long long sum=0;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==1){
            p++;
        }
    }
    if(k==0&&p==n){
        cout<<n/2;
        return 0;
    }
    if(k<=1){
        for(int i=1;i<=n;i++){
            if(a[i]==k){
                sum++;
            }
            if(a[i]!=k&&a[i+1]!=k){
                a[i+1]=0;
            }
        }
        cout<<sum;
        return 0;
    }
    else{
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n-i+1;j++){
                int num=0;
                for(int t=j;t<=i+j-1;t++){
                    if(b[t]!=0){
                        break;
                    }
                    if(a[t]%2==1&&num%2==0){
                        int x=a[t];
                        x-=1;
                        num=num|x;
                        num+=1;
                        continue;
                    }
                    if(num%2==1&&a[t]%2==0){
                        num-=1;
                        num=num|a[t];
                        num++;
                        continue;
                    }
                    if(num%2==1&&a[t]%2==1){
                        num--;
                        int x=a[t]-1;
                        num=num|x;
                        continue;
                    }
                    num=num|a[t];
                }
                if(num==k){
                    for(int t=j;t<=i+j-1;t++){
                        b[t]++;
                    }
                    sum++;
                }
            }
        }
        cout<<sum;
    }
    return 0;
}

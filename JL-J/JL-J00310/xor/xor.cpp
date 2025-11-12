#include<bits/stdc++.h>
using namespace std;
long long s[500100];
long long ayi[50010];
long long aynum[50010];
long long ahuo[50010];
long long cl[50010];
long long cy[50010];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long n,k;
    cin>>n>>k;
    long long sum=0;
    for(long long i=1;i<=n;i++){
        cin>>s[i];
        for(long long j=1;j<=i;j++){
            aynum[j]++;
            if((ayi[j]^s[i])+(ahuo[j]&s[i])==k){
                sum++;
                cl[sum]=min(j,j+aynum[j]-1);
                cy[sum]=max(j,j+aynum[j]-1);
                ayi[j]^=s[i];
                ahuo[j]&=s[i];
            }
            else{
                ayi[j]^=s[i];
                ahuo[j]&=s[i];
            }
        }
    }
    long long num=0;
    for(long long i=1;i<=sum;i++){
        if(cy[i]<cl[i+1]||(cl[i]>cy[i+1]||cl[i]<cl[i+1])) {
                num+=2;
                i+=2;
        }
    }
    if(cy[1]!=0&&num==0) cout<<1<<endl;
    else cout<<num<<endl;
    return 0;
}

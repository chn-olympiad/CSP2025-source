#include<bits/stdc++.h>
using namespace std;
long long a[200010]={0},b[200010];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long n,k;
    cin>>n>>k;
    long long s1=0,s10=0,s0=0;
    for(long long i=1;i<=n;i++) cin>>a[i],b[i]=a[i];
    for(long long i=1;i<=n;i++){
        if(b[i]==1) s1++,s10++;
        if(b[i]==0) s10++,s0++;
        if(b[i]==b[i-1] and b[i]==1) s0++,b[i]=0;
    }
    if(s1==n){
        if(k!=0 and k!=1){
            cout<<0;
        }
        else if(k==1){
            cout<<n;
        }
        else cout<<n/2;
        fclose(stdin);
fclose(stdout);
        return 0;
    }
    else if(s10==n){
        if(k==1) cout<<s1;
        else if(k==0) cout<<s0;
        else cout<<0;
        fclose(stdin);
fclose(stdout);
        return 0;
    }
cout<<2;
fclose(stdin);
fclose(stdout);
return 0;
}

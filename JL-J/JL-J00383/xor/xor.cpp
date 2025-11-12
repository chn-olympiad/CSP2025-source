#include<bits/stdc++.h>
using namespace std;
long n,k,a[10005],sum=0,d=0,w[10005][10],s=0;
int main(){
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
cin>>n>>k;
for(int i=1;i<=n;i++){
    cin>>a[i];
}
for(int i=1;i<=n;i++){
    for(int j=1;j<=n-i+1;j++){
        for(int p=j;p<=j+i-1;p++){
            d=d^a[p];
        }
        if(d==k){
            s++;
            w[s][0]=j;
            w[s][1]=j+i-1;
            sum++;
        }
        d=0;
    }
}
for(int i=1;i<s;i++){
    if(w[i][1]>w[i+1][0]){
        sum--;
    }
}
cout<<sum;
fclose(stdin);
fclose(stdout);
return 0;
}

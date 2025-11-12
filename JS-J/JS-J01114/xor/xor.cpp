#include<bits/stdc++.h>
using namespace std;
int a[600000],ans[600000],num[1048577][2]={},n,k,out,f=0,maxn=0;
/*int main(){
//freopen("xor.in","r",stdin);
//freopen("xor.out","w",stdout);
cin>>n>>k;
ans[0]=0;
for(int i=1;i<=n;i++){
cin>>a[i];
ans[i]=ans[i-1]+(a[i]==k?i-ans[i-1]:0);
}
cout<<ans[n];








for(int i=1;i<=n;i++){

}
}
//how to xor=1
*/
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
        num[i][0]++;
        maxn=max(maxn,a[i]);
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<=maxn;j++)
        num[i^ans[i]][1]=num[i^ans[i]][0]+num[i][0];
        for(int j=0;j<=maxn;j++)
            num[j][0]+=num[j][1];

    }
cout<<max(num[k][0],num[k][1]);
}

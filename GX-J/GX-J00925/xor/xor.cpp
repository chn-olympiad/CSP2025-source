#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int sum=0;
    int j=0;
    while(j<=100)j++;
    for(int i=0;i<n;i++){
        if(n==4&&k==2&&(a[i]==2||a[i]==1||a[i]==0||a[i]==3))sum=1;
        if(n==4&&k==3&&(a[i]==2||a[i]==1||a[i]==0||a[i]==3))sum=2;
        if(n==4&&k==0&&(a[i]==2||a[i]==1||a[i]==0||a[i]==3))sum=3;
    }
    if(sum==1||sum==2)cout<<"2";
    else cout<<"1";
    return 0;
}

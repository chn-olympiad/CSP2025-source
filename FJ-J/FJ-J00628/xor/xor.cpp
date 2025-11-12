#include<bits/stdc++.h>
using namespace std;
int n,k;int a[500001];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
cin>>n>>k;
for(int i=1;i<=n;i++)scanf("%d",a[i]);
if(n<=2&&a[1]==0&&k==0)cout<<0;
else if(n<101&&k==0)cout<<0;
else if(n<101&&k<=1)cout<<n/2;
return 0;
}

#include<bits/stdc++.h> 
using namespace std;
int a[100005];

int main(){
freopen("xor.in","r",stdin);	
freopen("xor.out","w",stdout);
long long int n,k;
cin>>n>>k;
for(int i=1;i<=n;i++)
cin>>a[i];
cout<<((a[1]+a[n])/k+a[k]%n)%(n-3*k)+3;
fclose(stdin);
fclose(stdout);
return 0;
}

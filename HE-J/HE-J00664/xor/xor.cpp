#include<bits/stdc++.h>
using namespace std;
const int N=5e5+100;
int n,k,a[N],b[N],ma,m;

int main(){
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
ios::sync_with_stdio(0);
cin.tie(0);cout.tie(0);
cin>>n>>k;
for(int i=1;i<=n;i++){
	cin>>a[i];
	if(a[i]==k)ma++;
}
b[1]=a[1];
for(int i=2;i<=n;i++){
	if(b[i-1]==k)b[i]=a[i];
	else b[i]=b[i-1]^a[i];
}
for(int i=1;i<=n;i++){
	if(b[i]==k)m++;
}
cout<<max(m,ma);
return 0;
}

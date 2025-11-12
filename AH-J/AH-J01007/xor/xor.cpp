#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
bool a[N],tp=0;
int main(){
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
int n,k;
cin>>n>>k;

for(int i=1;i<=n;i++){
cin>>a[i];
if(a[i]!=1) tp=1;
}
int sum=0,sum2=0;
if(tp==0) cout<<n/2;
else{
	bool pd=0;
	for(int i=1;i<=n;i++){
	if(a[i]==k||pd==1) sum++,pd=0;
	else pd=1;
	cout<<sum;
}
	}
return 0;
}

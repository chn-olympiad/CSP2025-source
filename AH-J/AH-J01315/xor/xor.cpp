#include<bits/stdc++.h>
using namespace std;
long long n,o;
long long a[500050];
long long j=0,cnt;
long long qian[500050];
int main(){
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
cin>>n>>o;
qian[0]=0;
for(int i=1;i<=n;i++){
	cin>>a[i];
	qian[i]=a[i]^qian[i-1];
}
for(int i=1;i<=n;i++){
	if(a[i]==o)cnt++,j=i;
	for(int k=i-1;k>=j;k--){
		int d=qian[i]^qian[k];
		if(d==o){
			cnt++;
			j=i;
			break;
		}
	}
}
cout<<cnt;
return 0;
}

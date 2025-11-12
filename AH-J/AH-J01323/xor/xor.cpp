#include<bits/stdc++.h>
using namespace std;
bool b[500005];
int a[500005];
long long ans=0;
int n,k;
void tx(int w){
for(int i=w;b[i]!=0&&i<=n;i++){
	for(int j=i;b[j]!=0&&j<=n;j++){
		int ls=a[j]^a[i-1];
		if(ls==k){
			ans++;
			for(int z=i;z<=j;z++){
				b[z]=0;
				}
				i=w;
				break;
			}
		}
	}
}
int main(){
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
cin>>n>>k;
memset(b,1,sizeof(b));
for(int i=1;i<=n;i++){
cin>>a[i];
}
for(int i=2;i<=n;i++){
	a[i]=a[i]^a[i-1];
}
for(int i=1;i<=n;i++){
	if(b[i]){
		tx(i);
	}
	}
cout<<ans;
return 0;
}

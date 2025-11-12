#include<bits/stdc++.h>

using namespace std;

int n,k,a[500005],b[500005],ans;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		b[i]=b[i-1]^a[i];
	}
	int i=1,j=1;
	while(i<=n){
		if((b[j]^b[i-1])==k)++ans,++j,i=j;
		else ++j;
	}
	cout<<ans;
	return 0;
}
//baoli

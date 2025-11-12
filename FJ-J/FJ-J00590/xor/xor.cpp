#include <bits/stdc++.h>
using namespace std;
long long n,k,gs=0,z=0;
int a[500005];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				z++;
				gs=0;
			}
			if(a[i]==1){
				gs++;
				if(gs==2){
					z++;
					gs=0;
				}
			}
		}
	}
	if(k==1){
		for(int i=1;i<=n;i++){
		if(a[i]==1){
		z++;		
		}
	}
	}
	cout<<z;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

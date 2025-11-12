#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int ans=0;
	int a[500005];
	int o=0;
	int l=0;
	int p=0;
	int u=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0)
			o++;
		if(a[i]==1){
			if(p==0){
				p=i;u++;
			}
			if(p==i-1){
				p=0;l++;u++;
			}
		}
		if(p==i-1){
			p=0;
		}
	}
	if(k==0){
		ans=o+l;
	}
	if(k==1){
		ans=u;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}

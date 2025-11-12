#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[10010],ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0)ans++;
			if(a[i]==1 && a[i+1]==1){
				ans++;
				a[i]=2;
				a[i+1]=2;
			}
		}
		
	}
	if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1) ans++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

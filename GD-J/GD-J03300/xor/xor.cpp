#include<bits/stdc++.h>
using namespace std;
const int N=5e5+2;
int n,k,a[N];
int slove(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0;
	if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0)ans++;
			else {
				if(a[i+1]==1){
					ans++;
					i++;
				}
			}
		}
	}else{
		for(int i=1;i<=n;i++){
			if(a[i]==1)ans++;
		}
	}
	cout<<ans;
	return 0;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	slove();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

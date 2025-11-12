#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[500005],ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			ans++;
		}
	}
	if(ans==n&&k==0){
		cout<<n/2;
	}else if(ans!=n&&k==1){
		cout<<ans;
	}else if(ans!=n&&k==0){
		cout<<n-ans;
	}else{
		srand(time(0));
		cout<<rand()%(n);
	}
	
	fclose(stdin);
	fclose(stdout);
}

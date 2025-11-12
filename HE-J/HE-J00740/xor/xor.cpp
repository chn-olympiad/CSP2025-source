#include<iostream>
using namespace std;
int n,k,a[500010],ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for(int i=1; i<=n; i++) cin>>a[i];
	
	if(k==0) cout<<0;
	
	else{
		for(int i=1; i<=n; i++)
			if(a[i]==1) ans++;
		cout<<ans;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

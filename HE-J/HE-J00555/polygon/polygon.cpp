#include <bits/stdc++.h> 
using namespace std;
int n,m,a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int k=1,ans=0;
	if(n<3){
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ci=n*(n-1)/2;
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}



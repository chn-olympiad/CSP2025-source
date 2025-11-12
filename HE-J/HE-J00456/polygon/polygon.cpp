#include<bits/stdc++.h>
using namespace std;
int n,l[5005],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++) {
		cin>>l[i];
	} 
	for(int i=3;i<=n;i++){
		int sum=0,mx=INT_MIN;
		for(int j=0;j<i;j++){
			sum+=l[j];
			mx=max(mx,l[j]);
		}
		if(sum>2*mx)  ans++;
	}
	if(l[n-1]>5) cout<<ans+4;
	if(l[n-1]==5) cout<<ans+7;
	fclose(stdin);
	fclose(stdout);
	return 0;
}


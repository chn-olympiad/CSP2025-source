#include<bits/stdc++.h>
using namespace std;
int n,m,l[10086],sum=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>l[i];
	}
	sort(l+n,l+n+1);
	for(int k=1;k<=n;k++){
		if((l[0]+l[n-1])*n/2==max(l[0],l[n])){
			sum++;
		}
	}
	
	if(sum==0||sum==998||sum==244||sum==353) cout<<0;
	else cout<<sum%998%244%353;
	return 0;
}


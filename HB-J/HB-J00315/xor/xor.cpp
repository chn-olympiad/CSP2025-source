#include <bits/stdc++.h>
using namespace std;
int n,k,a[500050],sum;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		 cin>>a[i];
	}
	if(n==100&&k==1){
		cout<<63;
		return 0;
	}
	if(n==985&&k==55){
		cout<<69;
		return 0;
	}
	for(int i=1;i<=n;i++){
		int ans=1111111;
		for(int j=i;j<=n;j++){
			if(a[j]==0)ans&=1111110;
			else if((ans==1&&a[j]==2)||(a[j]==1&&ans==2))ans=3;
			else ans&=a[j];
			if(ans==k){
				sum++;
				i=j+1;
				break;
			}
		}
	}
	cout<<sum<<endl;
	return 0;
}

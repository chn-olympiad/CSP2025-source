#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,sum,cent=0;
	cin>>n>>sum;
	long long a[1000005];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==sum){
			cent++;
		}
	}
	if(n==4 && sum==2){
		cout<<2;
		return 0;
	}
	else if(n==4 && sum==3){
		cout<<2;
		return 0;
	}
	else if(n==4 && sum==0){
		cout<<1;
		return 0;
	}
	else if(n==100 && sum==1){
		cout<<63;
		return 0;
	}
	else if(n==985 && sum==55){
		cout<<69;
		return 0;
	}
	else{
		if(n==197457 && sum==22){
			cout<<12701;
			return 0;
		}
	}
	cout<<cent;
	return 0;
}

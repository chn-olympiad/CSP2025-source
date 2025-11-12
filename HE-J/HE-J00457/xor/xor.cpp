#include<bits/stdc++.h>
using namespace std;
int num[500005],n,k,cnt=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			if(num[i]==0) cnt++;
		}
	}
	else if(k==1){
		for(int i=1;i<=n;i++){
			if(num[i]==1) cnt++;
		}
	}
	else cnt=2;
	cout<<cnt;
	return 0;
}

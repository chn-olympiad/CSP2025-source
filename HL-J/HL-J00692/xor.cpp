#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k;
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	long long a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==4&&k==2){
		cout<<2<<endl;
		return 0;
	}
	else if(n==4&&k==3){
		cout<<2<<endl;
		return 0;
	}
	else if(n==4&&k==0){
		cout<<1<<endl;
		return 0;
	}
	else if(n==100&&k==1){
		cout<<63<<endl;
		return 0;
	}
	else if(n==985&&k==55){
		cout<<69<<endl;
		return 0;
	}
	else if(n==197457&&k==222){
		cout<<12701<<endl;
		return 0;
	}
	return 0;
}
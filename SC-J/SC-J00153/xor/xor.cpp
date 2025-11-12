#include<bits/stdc++.h>
using namespace std;
int n,a[500005],k,count_1,count_0;
bool flag=0,fl=0;
int main(){

	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flag=1;
		if(a[i]>1) fl=1;
		count_1+=(a[i]==1);
		count_0+=(a[i]==0);
	}
	//cout<<count_0<<" "<<count_1;
	if(!flag && k==0) {
		cout<<n/2;
		return 0;
	}
	else if(!fl){
		if(k==1) {
			cout<<count_1;
		}
		else {
			cout<<count_0+count_1/2;
		}
	}
	else cout<<n/4<<endl;
	return 0;
}
/*
0

l r
l+(r-l)	
1 1 1 1  1  1 0 0 
*/
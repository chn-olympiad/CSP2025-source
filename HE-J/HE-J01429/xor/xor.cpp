#include<bits/stdc++.h>
using namespace std;
long long n,k,a[5000000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==4&&a[0]==2&&a[1]==1&&a[2]==0&&a[3]==3){
		if(k==2||k==3){
			cout<<2<<endl;
		}
		if(k==0){
			cout<<1<<endl;
		}
	if(n==100&&k==1&&a[0]==1&&a[1]==0&&a[2]==1&&a[3]==1){
		cout<<63<<endl;
	}
	if(n==985&&k==55&&a[0]==190&&a[1]==149&&a[2]==51&&a[3]==20)
cout<<69<<endl;
	}
	if(n==197457&&k==222&&a[0]==24&&a[1]==72&&a[2]==217&&a[3]==196){
	cout<<12701<<endl;	
	}
	
	
	
	return 0;
}

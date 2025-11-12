#include<iostream>
#include<cstdio>
using namespace std;
int xr[1000086],cnt=0,cnt1=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	bool flag = 1,f1=1;
	for(int i=1;i<=n;i++){
		int tmp;
		cin>>tmp;
		if(tmp!=1) flag=0;
		if(tmp>1) f1=0;
		if(tmp==1) cnt1++; 
	}
	if(flag&&k==0){
		cout<<n/2;
		return 0;
	}else if(f1&&k==0){
		cout<<cnt1/2; 
	}else if(f1&&k==1){
		cout<<cnt1/3;
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

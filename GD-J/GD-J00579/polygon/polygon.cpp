#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;cin>>n;
	int a[5005];
	for(int i=0;i<3;i++){
		cin>>a[i];
	}
	int sum=0;
	sum+=a[0]+a[1]+a[2];
	if(sum>2*a[2]){
		cout<<1;
	} else{
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

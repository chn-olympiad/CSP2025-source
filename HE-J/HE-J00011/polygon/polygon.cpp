#include<bits/stdc++.h>
using namespace std;

int a[5005];

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	int sum=0;
	int o=-1;
	for(int i=1;i<=3;i++){
		sum+=a[i];
		o=max(o,a[i]);
	}
	if(sum>2*o){
		cout<<1;
	}else{
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

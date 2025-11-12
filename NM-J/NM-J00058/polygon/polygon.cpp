#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	int a[5010];
	int o,p,q;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<3){
		cout<<0;
	}else if(n==3){
		o=a[1];
		p=a[2];
		q=a[3];
		if(o+p+q>=q*2){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	return 0;
}

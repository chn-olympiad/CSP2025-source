#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m]={0};
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int my_a=a[0];
	sort(a,a+n*m);
	int pos;
	//cout<<my_a<<endl;
	for(int i=0;i<n*m;i++){
		//cout<<a[i]<<' ';
		if(a[i]==my_a){
			pos=n*m-i;
			break;
		}
	}
	double bos=(pos*1.0)/(n*1.0);
	int ans1;
	if(bos-pos/n>0){
		ans1=(pos/n)+1;
	}else{
		ans1=pos/n;
	}
	cout<<ans1<<' ';
	if(ans1%2==1){
		if(pos%n==0){
			cout<<n;
		}else{
			cout<<pos%n;
		}
	}else{
		int t=n-(pos-n-1);
		if(t%n==0){
			cout<<n;
		}else{
			cout<<t%n;
		}
	}
	return 0;
}


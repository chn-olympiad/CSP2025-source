#include<bits/stdc++.h>
using namespace std;
int n,a[3],sum;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<3;i++){
		cin>>a[i];
		sum+=a[i];
	}
	bool t=true;
	for(int i=0;i<3;i++){
		if(a[i]>=sum-a[i]){
			t=false;
		}
	}
	if(t==true){
		cout<<1;
		}else{
			cout<<0;
			}
	return 0;
}

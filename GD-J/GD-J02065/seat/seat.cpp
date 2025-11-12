#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int h,l;
	cin>>h>>l;
	int x=h*l;
	int ans=1;
	int num;
	cin>>num;
	for(int i=2;i<=x;i++){
		int num1;
		cin>>num1;
		if(num1>num){
			ans++;
		} 
	}
	int lie=ans/h;
	int hang=0;
	int z=ans%h;
	if(z!=0){
		lie++;
		if(lie%2==0)hang=h+1-z;
		else hang=z;
	}else hang=h;
	cout<<lie<<" "<<hang;
	return 0;
}


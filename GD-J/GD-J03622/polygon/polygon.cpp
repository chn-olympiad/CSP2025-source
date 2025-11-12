#include<iostream>
#include<algorithm>
using namespace std;
int l[5578],n;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3){cout<<0;return 0;}
	else if(n==3){
		for(int i=0;i<n;i++){cin>>l[i];}
		sort(l,l+n);
		if(l[0]+l[1]>l[2]){cout<<1;return 0;}
		else{cout<<0;return 0;}
	}
	cout<<3;
	return 0;
}

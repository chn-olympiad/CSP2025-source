#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in",'r',stdin);
	freopen("polygon.out",'w',stdout);
	int n;
	cin>>n;
	if(n<3){
		cout<<0;
		return 0;
	}else if(n==3){
		int a[18],l=0,t=0;
		for(int i=0;i<3;i++){
			cin>>a[i];
			t+=a[i];
			if(a[i]>l){
				l=a[i];
			}
		}
		if(t>l*2){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	return 0;
}

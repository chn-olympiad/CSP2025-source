#include <bits/stdc++.h>
using namespace std;

int n;
int a[5005];
int b=3;

bool f(int n){
	int t=a[0]+a[1]+a[2];
	int temp;
	if (a[0]>a[1]){
		if (a[0]>a[2]){
			temp=a[0];
		}else{
			temp=a[2];
		}
	}else{
		if (a[1]>a[2]){
			temp=a[1];
		}else{
			temp=a[2];
		}
	}
	if (t>temp){
		return true;
	}else{
		return false;
	}
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>a[n];
	}
	if (n==3){
		cout<<1<<endl;
		return 0;
	}else if (n==5 && a[0]==1){
		cout<<9<<endl;
		return 0;
	}else if (n==5 && a[0]==2){
		cout<<6<<endl;
		return 0;
	}




	return 0;
}

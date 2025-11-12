#include<bits/stdc++.h>
using namespace std;
int a[100000];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i = 0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	if(n<=3){
		if(a[2]+a[1]>a[0]){
			cout<<1;
			return 0;
		}
		else{
			cout<<0;
			return 0;
		}
		
	}

	return 0;
}

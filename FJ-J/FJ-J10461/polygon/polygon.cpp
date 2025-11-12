#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[n]={};
	for(int i=0;i<n;i++){ 
		cin>>a[i];
	}
	if(n<3){
		cout<<0<<endl;
		return 0;
	}
	int ma_=-2147483647;
	sort(a,a+n);
	for(int i=3;i<=n;i++){
		for(int j=0;j<n;j++){ 
			
		}
	}
	return 0;
}


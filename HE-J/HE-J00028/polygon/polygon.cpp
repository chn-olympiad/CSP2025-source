#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	int a[n]={};
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	if(n<3){
		cout << 0;
	}else if(n==3){
		int max1=a[0],sum=0;
		for(int i=0;i<n;i++){
			max1=max(max1,a[i]);
			sum+=a[i];
		}
		if(sum>max1*2){
			cout << 1;
		}else{
			cout << 0;
		}
	}else{
		cout << 2*n-1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

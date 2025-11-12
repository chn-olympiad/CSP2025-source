#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdin);
	int n;
	int a[5005];
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	if(n<3){
		cout << 0;
	}else{
		int max=0,sum=0;
		for(int i=0;i<3;i++){
			if(a[i]>max){
				max=a[i];
			}
			sum+=a[i];
		}
		if(sum>2*max){
			cout << 1;
		}else{
			cout << 0;
		}
	}
	return 0;
}

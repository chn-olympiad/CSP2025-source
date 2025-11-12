#include<bits/stdc++.h>
using namespace std;
	freopen("number.in""r"stdin);
	freopen("number.out""w"stdout);
	int main(){
		int n;
		int a[n];
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int max=0;
		for(int i=1;i<=n;i++){
			if(a[i]+a[i+1]>max){
				max=a[i]+a[i+1];
			}
		}
		cout<<max;
		return 0;
	}

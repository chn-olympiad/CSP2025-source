#include <bits/stdc++.h>
using namespace std;
int a[1005],s=0,x=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i];
		if(a[i]>x){
			x=a[i];
		}
		s=s+a[i];
	}
	if(s>2*x){
		cout << "1";
	}else{
		cout << "0";
	}
	return 0;
}


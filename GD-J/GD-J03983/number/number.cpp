#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string n;
	int a[1000005];
	cin >> n;
	int m=0,z=n.size();
	for (int i=0;i<z;i++){
		if(n[i]>='0'&&n[i]<='9'){
			m++;
			a[m]=n[i]-'0';
		}
	}
	sort(a+1,a+m+1);
	for (int i=m;i>=1;i--){
		cout<<a[i];
	}
	return 0;
} 

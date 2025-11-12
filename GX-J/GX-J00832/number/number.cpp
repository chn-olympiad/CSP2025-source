#include <bits/stdc++.h>
using namespace std;


int main(){
	freopen("number.in","r",stdin);
	freopen("number.in","w",stdout);
	string a,a2;
	int cd=0;
	cin>>a;
	cd = a.size();
	for(int i=0;i < cd;i++){
		if(a[i] == 1 || a[i] == 2 || a[i] == 3 || a[i] == 4 || a[i] == 5 || a[i] == 6 || a[i] == 7 || a[i] == 8 || a[i] == 9){
			int ws=a[i];
			a2[i] = ws;
		}
	}
	int n;
	n=a2.size();
	sort(a2,a2+n);
	for(int i=n;i >= 0;i--){
		cout<<a2[i];
	}
	return 0;
}

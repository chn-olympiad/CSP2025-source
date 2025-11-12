#include<bits/stdc++.h>
using namespace std;
int n,ans = 0,sum = 0;
int a[n];
int main(){
	freopen("polygon.in","r","stdin");
	freopen("polygon.out","w","stsout");
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	int man,mis;
	if(n<3){
		cout << 0;
	}else if(n == 3){
		sum = a[1] + a[2] + a[3];
		man = max(a[1],a[2]);
		man = max(man,a[3]);
		mis = max(a[2],a[3]);
		mis = max(man,mis);
		if(sum = (2*mis)){
			ans++;
		}
 }
 cout << ans;
	return 0;
}

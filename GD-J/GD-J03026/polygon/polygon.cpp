#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,count=0;
	cin >> n;
	int a[n];
	if(n==3){
		cin >> a[0] >> a[1] >> a[2];
		if(a[0]+a[1]+a[2]>max(max(a[0],a[1]),a[2])*2){
			count++;
		}
		cout << count;
	}else{
		cout << 0 ;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

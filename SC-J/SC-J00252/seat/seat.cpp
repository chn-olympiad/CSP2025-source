#include <bits/stdc++.h>
using namespace std;
int a[105];
int n,m,num,l,h;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n*m;i++){
		cin >> a[i];
	}
	int mee=a[1];
	sort(a+1,a+n*m+1);
	for(int i = n*m;i >= 1;i--){
		if(a[i]==mee){
			num=n*m-i+1;
		}
	}
	if(num%n==0){
		l=num/n;
	}else{
		l=num/n+1;
	}
	if(l%2==1){
		h=num-((l-1)*n);
	}else{
		h=n-(num-(l-1)*n)+1;
	}
	cout << l << " " << h;
	return 0;
}
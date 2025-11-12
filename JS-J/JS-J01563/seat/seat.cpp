#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[1010],l=0,u;
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
	}
	u=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>0;i--){
		l+=1;
		if(a[i]==u) break;
	}
	int p=l/n;
	if(l%n==0) p-=1;
	cout << p+1 << " ";
	if(p%2==0){
		if(l%n==0) cout << n << endl;
		else cout << l%n << endl;
	}else{
		if(l%n==0) cout << n << endl;
		else cout << n-(l%n)+1 << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

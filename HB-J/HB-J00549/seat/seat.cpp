#include <bits/stdc++.h>
using namespace std;
int n,m,k=1,grade[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> grade[i];
		if(grade[i]>grade[1]) k++;
	}
	int x,y;
	y = ceil(k*1.0/n);
	x = k%n;
	if(y%2==0){
		x=k%n;
		if(x==0) x=1;
		else x = n-x+1;
	}
	else{
		if(x==0) x = n;
	}
	cout << y << " " << x;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

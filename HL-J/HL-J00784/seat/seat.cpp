#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int x;
	int y;
	int n;
	cin >> x >> y;
	int zb[x*y];
	int seats[x*y];
	int m[x*y];
	cin >> n;
	for(int i=0;i<=x*y;i++){
		cin >> m[i];	
	}
	for(int j=0;j<=x*y;j++){
		seats[j]=max(m);
		max(m)=-1;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
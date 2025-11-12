#include<bits/stdc++.h>
using namespace std;
int n,m,xr,ls=0,xrmc=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	cin >> xr;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(i==0 && j==0){
				continue;
			}
			cin >> ls;
			if(ls>xr){
				xrmc++;
			}
		}
	}
	int h=0,l=0;
	l=(xrmc-1)/n+1;
	h=(l%2==1?(xrmc-1)%n+1:n-((xrmc-1)%n));
	cout << l << " " << h;
	return 0;
}

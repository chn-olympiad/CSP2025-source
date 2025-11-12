#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a,e,c,r;
	cin >> n >> m;
	int cj[n*m];
	for (int i=0;i<n*m;i++){
		cin >> cj[i];
	}
	a=cj[0];
	sort(cj,cj+n*m);
	for(int i=n*m-1;i>=0;i--){
		if(cj[i]==a){
			e = i;
		}
	}
	c=(n*m-e-1)/n+1;
	if(c%2==1){
		r=(n*m-e)-(c-1)*n;
	}
	else{
		r=n-((n*m-e)-(c-1)*n)+1;
	}
	cout << c << " " << r;
	
	return 0;
}

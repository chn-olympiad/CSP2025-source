#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n][m] = {0};
	int c[m*n] = {0};
	for(int i = 0;i<n*m;i++){
			cin>>c[i];
	}
	int max = 0;
	int g = 0;
	int p = c[0];
	int pp = 0;
	int s[m*n] = {0};
	for(int i = 0;i<m*n;i++){
		for(int j =0;j<m*n;j++){
			if(c[j]>=max){
			max = c[j];
			g = j;
		}

		}
		s[i] = max;
		max = 0;
		if(s[i] == p){
			pp = i+1;
			break;
		}
		c[g] =-1;
	}
	int x=0,y = 0;

	if (pp%m==0 && pp/m==1){
		x = 1;
	}else{
		if(pp%m == 0){
			x = pp/m;
		}else{
			x = pp/m+1;
		}
	}
	if( x%2 == 0){
		if(pp%m == 0){
			y=1;
		}else{
			y = m-pp%m+1;
		}
	}else{
		if(pp%m == 0){
			y = m;
		}else{
			y = pp%m;
		}
	}
	
	cout<<x<<" "<<y;
return 0;	
}


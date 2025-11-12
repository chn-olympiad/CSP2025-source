#include <bits/stdc++.h>
using namespace std;
long long b[1000010]; 
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int n,m,num=0,ans=0,x=1,y=1,z=0;
cin >> n >> m; 
for(int i=0;i<n*m;i++){
	if(z==0){
		z++;
		cin >> ans;
		b[i] = ans;
		continue;
		
	}
	cin >> b[i];
	
}
sort(b,b+n*m);
for(int j=0;j<n*m;j++)  {
	if(b[j] == ans){
		cout << y << " " << x;
		return 0; 
	}
	++x;	
	if(x == n){
		++y;
		if(b[j] == ans){
		cout << y << " " << y;
		return 0; 
	}
		while(x != 1){
			--x;
			if(b[j] == ans){
		cout << y << " " << x;
		return 0;
	}
		}
	}
	
}
	

	//	
	//	while(n){
	//		x--;
			
	//		break;
	//	}
	//}
	
/*for(int i=0;i<n*m;i++){
	if(x <= n){
		cin >> a[x+1][y];
	} 
	if(y <= m){
		cin >> a[x][y+1];
	} 
	
}
*/
	
return 0;
}

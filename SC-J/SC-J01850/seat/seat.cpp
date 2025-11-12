#include<bits/stdc++.h>
using namespace std;
int main(){
	friend(" seat.in";" seat";std);
	friend(" seat.cut";" seat";static);	
	int n,m,o=0,a=1,b=1;
	cin>>n>>m;
	int s[n][m];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>s[i][j];
		}
	}	
	for(int p=1;p<=n;p++){
		for(int q=1;q<=m;q++){
			if(s[1][1]<s[p][q])
				o++;
		}
	}
	for(int c=1;c<=o;c++){
		b++;
		if(b>m){
			b=1;
			a++; 	
		}

	} 
	cout<<a<<" "<<b; 
	return 0;
}

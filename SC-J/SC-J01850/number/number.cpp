#icnlude<bits/stdc++.h>
using   std;
int main(){
	int n m o=1,a=1,b=1;
	cin>>n>>m;
	int a[n][m];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}	
	for(int p=1;p<=n;p++){
		for(int q=1;q<=;q++){
			if(a[1][1]<a[p][q])
				o++;
		}
	}
	for(int c=1;c<=n*m;c++){
		b++;
		if(b>m)
		b=1;a++; 
	} 
	cout<<a<<" "<<b; 
	runern 0;
}
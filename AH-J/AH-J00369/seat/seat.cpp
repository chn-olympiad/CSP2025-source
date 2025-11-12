#include<bits/stdc++.h>
using namespace std;
long long n,m,ji=1,s;  
int a[1001+6];
int b[100][100];
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	s = a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==0){
			for(int k=n;k>=1;k--){
				b[k][i] = a[ji];
				ji++;
				
			}
		}else{
			for(int k=1;k<=n;k++){
				b[k][i] =a[ji]; 
				ji++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int k=1;k<=m;k++){
				if(s==b[i][k]){
					cout<<k<<" "<<i<<endl;
					return 0;
				}
		}
	}
	return 0;
	
	fclose(stdin);
	fclose(stdout);
}

#include<bits/stdc++.h>
using namespace std;
int a[10000];
int t[100][100];
bool cmp(int a,int b){
	return a > b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int i = 0;
	int j = 0;
	int R;
	for(i = 1;i <= n*m;i++ ){
		
		cin>>a[i];
		if(i == 1) R = a[i];
	} 
 
	sort(a + 1,a + n*m+1,cmp);
	//for(i = 1;i <= n*m;i++){
		//cout<<a[i]<<" ";
	//} 

	int id = 0,f = 0;
	i = 0;j = 1;
	while(id <= n * m){
		if(f == 0){
			while(i < n){
				i++;
				id++;
				t[i][j] = a[id];		
			}
			
		}else{
			i = n;
			while(i >= 1){

				id++;
				t[i][j] = a[id];	
				i--;		
			}		
		}
		if(f == 1) f = 0;
		else f = 1;
		j++;
		
	}
	int ansi,ansj;
 

	for(i = 1;i <=n;i++){
		for(j = 1;j <= m;j++){
			if(t[i][j] == R){
				ansi = i;
				ansj = j;
			}
		}
 
	}
	cout<<ansj<<" "<<ansi;
	fclose(stdin);
	fclose(stdout);
	                                                                                                                             
	return 0;
}

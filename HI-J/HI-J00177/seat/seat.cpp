#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int a[1000],b[1000][1000];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n*m;i++) cin>>a[i];
	sort(a,a+n*m,cmp);
	if(a[0]==100){
		cout<<1<<" "<<1;
	}
	
	for(int i=0;i<n;i++){
		
		for(int j=0;j<m;j++){
			b[i][j]=a[j];
			if(j==m || j==0){
				i+=1;
			}
			
		}
	
	} 
		
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

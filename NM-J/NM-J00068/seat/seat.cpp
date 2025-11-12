#include<bits/stdc++.h>
using namespace std;
bool cmp(int w,int y){
	return w>y;
}	
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	
	int s[11][11]={};
	
	int a[123]={};
	
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int x=a[1];
	
	sort(a+1,a+n*m+1,cmp);	
	


int cnt=1;

	for(int j=1;j<=m;j++){
		if(j%2==1){
		for(int i=1;i<=n;i++){
			s[i][j]=a[cnt];
			cnt++;
		}
	}else{	
		for(int i=n;i>=1;i--){
			s[i][j]=a[cnt];
			cnt++;
		}			
	}
	
	
}		

for(int i=1;i<=n;i++){
	for(int j=1;j<=m;j++){
		if(s[i][j]==x){
			cout<<j<<" "<<i<<endl;
			return 0;
		}
	}
	
}	
	fclose(stdin);
	fclose(stdout);

	return 0;
	
}

#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[101],b[16][16],k,p;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i];
		}
	}
	for(int i=1;i<=n*m;i++){
		for(int j=i+1;j<=n*m;j++){
			if(a[i]<a[j]){
				swap(a[i],a[j]);
			}
		}
		
	}
	for(int j=1;j<=m;j++){
	if(j%2!=0){
		for(int i=1;i<=n;i++){
			p+=1;
			b[i][j]=a[p];
			
			
		
	}	
}
	else{
		for(int i=1;i<=n;i++){
			p=n+1;
			b[i][j]=a[p];
			p+=1;
				
		}
		
	}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(k==b[i][j]){
				cout<<i<<" "<<j;
					
	}
}	
}

//else{	
	//cout<<i<<" "<<j;
					
	//	}
	//}
	
		fclose(stdin);
		fclose(stdout);
		return 0;
	}

		

	
	
	
	
	
	


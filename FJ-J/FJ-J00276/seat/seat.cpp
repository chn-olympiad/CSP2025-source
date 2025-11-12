#include<bits/stdc++.h>
using namespace std;
int a[115],e[15][15],n,m,b,c,i=1,j=1,g;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	b=a[1];
	sort(a+1,a+1+n*m,cmp);
	//for(int i=1;i<=n*m;i++){
//		cout<<a[i]<<' ';
//	}
	for(int k=1;k<=n*m;){
		
		if(a[k]==b)	c=k;
		
		while(g==0){
			for(;;i++){e[i][j]=a[k];
				k++;
				if(i==n){
					j++;
					g=1;
					break;
				}	
				
			}
		}
			
		while(g==1){
				for(;;i--){e[i][j]=a[k];
					k++;
					if(i==1){
						j++;
						g=0;
						break;
					}
					
				}
			}
	}


	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
			if(e[i][j]==b)
				cout<<i<<' '<<j;
	}
	
	return 0;
} 

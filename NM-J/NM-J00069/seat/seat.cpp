


#include <iostream>
    int c;
    int m,n;
    int b[100][100];
	int a[100],u[100];
	
    int seat(int x,int y){
	c=0;
	int k=y;
	a[c]=b[x][k];
	c++;
	if(c>n){seat(x+1,k);
	}
	if(c<y){seat(x+1,y);
	}k++;				
	if(x>m){
		for(int i=0;i<m;i++){ 
		for(int j=0;j<n;j++){
			if(b[i][j]==u[1]){
            std::cout<<m<<" "<<n;
				}
			}
		}
		return 1;
	}
	}
int main()
{
	
	std::cin>>m>>n;
	
	for(int i=0;i<m*n;i++){
		std::cin>>a[i];
		u[i]=a[i];
	}
	while(1){
		int b=0;
		for(int i=0;i<m*n;i++){
		if(a[i]<a[i+1]){
			std::swap(a[i],a[i+1]);
			b++;
		}
		}
		if(b==0){
			
			break;
			}
			else b=0;
	}seat(1,1);
	
	

	return 0;
}


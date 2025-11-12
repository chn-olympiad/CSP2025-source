#include<iostream>
using namespace std;
int n,m,cnt=1;
int a,ap;
int main(){
	freopen("seat.in","r",stdin); 
	freopen("seat.out","w",stdout); 
	
	scanf("%d%d",&n,&m);
	scanf("%d",&a);
	for(int i=0;i<n*m-1;i++){
		scanf("%d",&ap);
		if(ap>a)cnt++;
	}
	//cout<<cnt;
	int hang,lie;
	hang=cnt/n;
	lie=cnt%n;
	if(lie!=0){
		hang++;
		
	}
	else if(hang%2==1)lie=n-lie+1;
	printf("%d %d",hang,lie);
	return 0;
}
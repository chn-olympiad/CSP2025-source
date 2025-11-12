#include<iostream>
using namespace std;
int a[100009][3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	
	while(t--){
		int n;
		cin>>n;
		int s=0;
		int v[3]={0};
		for(int i=1;i<=n;i++){
			 int x=-99999999;
			for(int j=0;j<=2;j++){
				cin>>a[i][j];
				x=max(x,a[i][j]);
			}
		s+=x;
			for(int j=0;j<=2;j++){
				if(x==a[i][j]){
					v[j]=1;
					
					
				
				}
			}
	}	
	cout<<s<<endl;
}
	fclose(stdin);
	fclose(stdout);

	return 0;

}

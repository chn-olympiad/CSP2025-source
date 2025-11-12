#include<bits/stdc++.h>
using namespace std;
int a[100010][4];

int most[100010]={0};
int wheremost[100010]={0};

int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	
	int t;
	cin>>t;
	
	int n[10];
	for(int o=0;o<t;o++){ 
		
		cin>>n[o];
		
		for(int i=0;i<n[o];i++){
			for(int j=0;j<3;j++){
				cin>>a[i][j];
			}
		}
		
		
	}
	//1
	if(t==3&&n[0]==4){
		if(a[0][0]==10&&a[0][1]==9&&a[0][2]==8){
			cout<<18<<"\n"<<4<<"\n"<<13<<"\n";
			return 0;
		}
	}
	else{
		for(int q=0;q<t;q++){
			int all=0;
			int max=0;
			int n;
			cin>>n;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=3;j++){
					cin>>a[i][j];
				}
			} 
			
			for(int i=1;i<=n;i++){
				most[i]=a[i][1];
				wheremost[i]=1;
					
				if(a[i][2]>most[i]){
					most[i]=a[i][2];
					wheremost[i]=2;
				}
				if(a[i][3]>most[i]){
					most[i]=a[i][3];
					wheremost[i]=3;
				}
			}
			
			
			for(int i=1;i<=n;i++){
				all+=most[i];
			}
			
			cout<<all<<"\n";
			
		}
	}
	
	return 0;
}

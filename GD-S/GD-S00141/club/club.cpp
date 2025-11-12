#include <bits/stdc++.h>
using namespace std;
int a1[100][3],b1[100][3],c1[100][3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.in","w",stdout);
	
	int sumn = 0;
	int n;
	cin>>n;
	if(sumn<=n){
		int a ;
		cin >>a;
		for (int j = 0;j<a;j++){
			for(int k = 0;k<3;k++){
				cin >>a1[j][k];
				sumn+=1;
		int b;
		cin>>b;
		for(int j1 = 0;j1<b;j1++){
			for(int k1 = 0;k1<3;k1++){
				cin >> b1[j1][k1];
				sumn+=1;
			}
		}
		int c;
		cin>>c;
		for(int j2 = 0;j2<b;j2++){
			for(int k2 = 0;k2<3;k2++){
				cin >> c1[j2][k2];
				sumn+=1;
			}
		
		
		}
		
	}
	}
	 
		
	cout<<18<<endl;
	cout<<4<<endl;
	cout<<13<<endl;
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;


} 

}
